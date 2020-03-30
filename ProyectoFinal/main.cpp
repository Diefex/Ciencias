#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "estructuras.h"
#include "arbolB.h"
#include "cola.h"

using namespace std;

// Crea las estructuras de iglesia con los datos almacenados en el archivo iglesias.txt
Arbol<ciudad>* buildIglesias(Arbol<ciudad>* ciudades){
	/* Estructura de iglesias.txt
	Ciudad
	Localidad
	Barrio
	Nombre
	Nombre del Lider
	Direccion
	*/
	ifstream fe("iglesias.txt");
	string dato;
	int l = 0;
	while(!fe.eof()) {
        fe >> dato;
        nodo<ciudad>* ciudad = ciudades->buscar(dato);
        if(ciudad == NULL){
      	  ciudad = ciudades->insertar(dato);
	    }
	    
	    fe >> dato;
	  	nodo<localidad>* localidad = ciudad->datos->localidades.buscar(dato);
	  	if(localidad == NULL){
	  		localidad = ciudad->datos->localidades.insertar(dato);
		}
		  
	  	fe >> dato;
	  	nodo<barrio>* barrio = localidad->datos->barrios.buscar(dato);
	  	if(barrio == NULL){
	  		barrio = localidad->datos->barrios.insertar(dato);
		}
		
		fe >> dato;
		nodo<iglesia>* ig = new nodo<iglesia>;
		ig->llave = dato;
		ig->der = ig->izq = NULL;
		
		ig->datos = new iglesia;
		fe >> ig->datos->lider;
		fe >> ig->datos->direccion;
		ig->datos->barrio = barrio->llave;
		
		localidad->datos->iglesias.insertar(ig);
		l++;
   }
   fe.close();
   return ciudades;
}

// Crea las estructuras de persona con los datos almacenados en el archivo database.txt
Arbol<ciudad>* buildFeligreses(Arbol<ciudad>* ciudades){
	/* Estructura de database.txt
	Ciudad
	Localidad
	Barrio
	Iglesia
	ID
	Nombre
	Apellido
	Tipo ID
	Genero
	Telefono Celular
	Telefono Fijo
	Email
	Fecha Nacimiento
	Ciudad de Nacimiento
	Pais de Nacimiento
	Direccion
	Actividad Laboral
	*/
	ifstream fe("database.txt");
	string dato;
	while(!fe.eof()) {
        fe >> dato;
        nodo<ciudad>* ciudad = ciudades->buscar(dato);
        if(ciudad == NULL){
      	  	ciudad = ciudades->insertar(dato);
	    }
	    
	    fe >> dato;
	  	nodo<localidad>* localidad = ciudad->datos->localidades.buscar(dato);
	  	if(localidad == NULL){
	  		localidad = ciudad->datos->localidades.insertar(dato);
		}
		  
	  	fe >> dato;
	  	nodo<barrio>* barrio = localidad->datos->barrios.buscar(dato);
	  	if(barrio == NULL){
	  		barrio = localidad->datos->barrios.insertar(dato);
		}
		
		  
		fe >> dato;
		nodo<iglesia>* iglesia = localidad->datos->iglesias.buscar(dato);
		if(iglesia == NULL){
			iglesia = localidad->datos->iglesias.insertar(dato);
		}
		
		fe >> dato;
		nodo<persona>* p1 = new nodo<persona>;
		nodo<persona>* p2 = new nodo<persona>;
		p1->llave = dato;
		p2->llave = dato;
		p1->der = p2->der = p1->izq = p2->izq = NULL;
		
		p1->datos = new persona;
		p2->datos = new persona;
		
		fe >> dato;
		p1->datos->nombre = dato;
		p2->datos->nombre = dato;
		
		fe >> dato;
		p1->datos->apellido = dato;
		p2->datos->apellido = dato;
		
		fe>> dato;
		p1->datos->tipoID = dato;
		p2->datos->tipoID = dato;
		
		fe>> dato;
		p1->datos->genero = dato;
		p2->datos->genero = dato;
		
		fe>> dato;
		p1->datos->telCelular = dato;
		p2->datos->telCelular = dato;
		
		fe>> dato;
		p1->datos->telFijo = dato;
		p2->datos->telFijo = dato;
		
		fe>> dato;
		p1->datos->email = dato;
		p2->datos->email = dato;
		
		fe>> dato;
		p1->datos->fechaNac = dato;
		p2->datos->fechaNac = dato;
		
		fe>> dato;
		p1->datos->ciudadNac = dato;
		p2->datos->ciudadNac = dato;
		
		fe>> dato;
		p1->datos->paisNac = dato;
		p2->datos->paisNac = dato;
		
		fe>> dato;
		p1->datos->direccion = dato;
		p2->datos->direccion = dato;
		
		fe>> dato;
		p1->datos->labor = dato;
		p2->datos->labor = dato;
		
		int edad = -1;
		fe >> edad;
		int i = 0;
		while(edad != -1) {
			nodo<hijo>* hijo_p1 = new nodo<hijo>;
			nodo<hijo>* hijo_p2 = new nodo<hijo>;
			
			hijo_p1->izq = hijo_p2->der = hijo_p1->der = hijo_p2->izq = NULL;
			stringstream ss;
			ss<<i;
			string llave;
			ss>>llave;
			hijo_p1->llave = llave;
			hijo_p2->llave = llave;
			
			hijo_p1->datos = new hijo;
			hijo_p2->datos = new hijo;
			
			hijo_p1->datos->edad = edad;
			hijo_p2->datos->edad = edad;
			
			p1->datos->hijos.insertar(hijo_p1);
			p2->datos->hijos.insertar(hijo_p2);
			fe >> edad;
			i++;
		}
		if(barrio->datos==NULL)cout<<"datos nulo";
		barrio->datos->personas.insertar(p1);
		iglesia->datos->personas.insertar(p2);
   }
   fe.close();
   
   return ciudades;
}

// Encuentra el nodo de tipo iglesia recorriendo el �rbol binario en preorden, para la lista de iglesias en la structura de localidades, con la llave pasada por par�metro.
nodo<iglesia>* find_iglesia(nodo<localidad>* raiz, string llave) {
	if(raiz!=NULL) {		
		nodo<iglesia>* ig = raiz->datos->iglesias.buscar(llave);
		if(ig!=NULL) return ig;
		ig = find_iglesia(raiz->izq, llave);
		if(ig==NULL) ig = find_iglesia(raiz->der, llave);
		return ig;
	}
	return NULL;
}

// Encuentra el nodo de tipo iglesia recorriendo el �rbol binario en preorden, con el llamdo de la funci�n find_iglesia de la parte superior;
nodo<iglesia>* find_iglesia(nodo<ciudad>* raiz, string llave) {
	if(raiz!=NULL) {
		nodo<localidad>* loc = raiz->datos->localidades.getRaiz();
		if(loc!=NULL) {
			nodo<iglesia>* ig = find_iglesia(loc, llave);
			if(ig!=NULL) return ig;
			ig = find_iglesia(raiz->izq, llave);
			if(ig==NULL) ig = find_iglesia(raiz->der, llave);
			return ig;
		}
	}
	return NULL;
}

// Recorre el �rbol binario en preorden, para la lista de hijos de la estructura persona, para contabilizar el n�mero de feligreses por rangos de edades de los hijos.
void recorrer_1(nodo<persona>* raiz, int* rango1Ptr, int* rango2Ptr, int* rango3Ptr, int* rango4Ptr, int* rango0Ptr) {
	if(raiz!=NULL) {
		nodo<hijo>* h = raiz->datos->hijos.buscar("0");
		if(h == NULL) {
			*rango0Ptr+=1;
		}
		int i = 0;
		bool r_1=false, r_2=false, r_3=false, r_4=false;
		while(h!=NULL) {
			if(h->datos->edad >= 0 && h->datos->edad <= 5 && !r_1){*rango1Ptr+=1; r_1=true;}
			else if(h->datos->edad >= 6 && h->datos->edad <= 10 && !r_2){*rango2Ptr+=1; r_2=true;}
			else if(h->datos->edad >= 11 && h->datos->edad <= 18 && !r_3){*rango3Ptr+=1; r_3=true;}
			else if(h->datos->edad > 18 && !r_4){*rango4Ptr+=1; r_4=true;}
			i++;
	   		stringstream ss;
	   		ss<<i;
	   		string llave;
	   		ss>>llave;
	   		h = raiz->datos->hijos.buscar(llave);
		}
		recorrer_1(raiz->izq, rango1Ptr, rango2Ptr, rango3Ptr, rango4Ptr, rango0Ptr);
		recorrer_1(raiz->der, rango1Ptr, rango2Ptr, rango3Ptr, rango4Ptr, rango0Ptr);
	}
}

// Recorre el �rbol binario en preorden, para la lista de hijos de la estructura persona, para contabilizar el n�mero de feligreses con un n�mero de hijos determindo por el usuario.
void recorrer_personas(nodo<persona>* raiz, int cota_inferior, int cota_superior) {
	if(raiz!=NULL) {
		if(raiz->datos->hijos.getNumNodos() >= cota_inferior && raiz->datos->hijos.getNumNodos() <= cota_superior){
			cout<<"\t\t"<<raiz->datos->nombre<<" "<<raiz->datos->apellido<<endl;
		}
		recorrer_personas(raiz->izq, cota_inferior, cota_superior);
		recorrer_personas(raiz->der, cota_inferior, cota_superior);
	}
}

// Recorre el �rbol binario en preorden, para la lista personas de la estructura barrio.
void recorrer_barrios(nodo<barrio>* raiz, int cota_inferior, int cota_superior) {
	if(raiz!=NULL) {
		recorrer_personas(raiz->datos->personas.getRaiz(), cota_inferior, cota_superior);
		recorrer_barrios(raiz->izq, cota_inferior, cota_superior);
		recorrer_barrios(raiz->der, cota_inferior, cota_superior);
	}
}

// Recorre el �rbol binario en preorden, para la lista barrios de la estructura localidades.
void recorrer_localidades(nodo<localidad>* raiz, int cota_inferior, int cota_superior) {
	if(raiz!=NULL) {
		cout<<"\t LOCALIDAD: "<<raiz->llave<<endl;
		recorrer_barrios(raiz->datos->barrios.getRaiz(), cota_inferior, cota_superior);
		recorrer_localidades(raiz->izq, cota_inferior, cota_superior);
		recorrer_localidades(raiz->der, cota_inferior, cota_superior);
	}
}

// Recorre el �rbol binario en preorden, para la lista localidades de la estructura ciduad.
void recorrer_ciudades(nodo<ciudad>* raiz, int cota_inferior, int cota_superior) {
	if(raiz!=NULL) {
		cout<<"CIUDAD: "<<raiz->llave<<endl;
		recorrer_localidades(raiz->datos->localidades.getRaiz(), cota_inferior, cota_superior);
		recorrer_ciudades(raiz->izq, cota_inferior, cota_superior);
		recorrer_ciudades(raiz->der, cota_inferior, cota_superior);
	}
}

/* 
	Recorre el �rbol binario en preorden, de la estructura persona para almacenar en una cola, 
	los feligreses con una actividda laboral determinasa por el usuario.
*/
void recorrer_personas_3(nodo<persona>* raiz, cola<nodo<persona>*>* artes, cola<nodo<persona>*>* ciencias_soc, cola<nodo<persona>*>* ingenierias, cola<nodo<persona>*>* salud, cola<nodo<persona>*>* otros) {
	
	if(raiz!=NULL) {
		if(raiz->datos->labor == "Artes") {
			artes->InsCola(raiz);
		}else if(raiz->datos->labor == "Ciencias_sociales") {
			ciencias_soc->InsCola(raiz);
		}else if(raiz->datos->labor == "Ingenieria") {
			ingenierias->InsCola(raiz);
		}else if(raiz->datos->labor == "Salud") {
			salud->InsCola(raiz);
		}else if(raiz->datos->labor == "Otros"){
			otros->InsCola(raiz);
		}
		recorrer_personas_3(raiz->izq, artes, ciencias_soc, ingenierias, salud, otros);
		recorrer_personas_3(raiz->der, artes, ciencias_soc, ingenierias, salud, otros);
	}
}

// Recorre el �rbol binario en preorden, para la lista de personas de la estructura barrio.
void recorrer_barrios_3(nodo<barrio>* raiz, cola<nodo<persona>*>* artes, cola<nodo<persona>*>* ciencias_soc, cola<nodo<persona>*>* igenierias, cola<nodo<persona>*>* salud, cola<nodo<persona>*>* otros) {
	if(raiz!=NULL) {
		recorrer_personas_3(raiz->datos->personas.getRaiz(), artes, ciencias_soc, igenierias, salud, otros);
		recorrer_barrios_3(raiz->izq, artes, ciencias_soc, igenierias, salud, otros);
		recorrer_barrios_3(raiz->der, artes, ciencias_soc, igenierias, salud, otros);
	}
}

/* 
	Recorre el �rbol binario en preorden, para la lista de barrios de la estructura localidad;
	adem�s, se crean apuntadores a colas para almacenar los feligreses en grupos de acuerdo a su actividad laboral.
*/
void recorrer_localidades_3(nodo<localidad>* raiz) {
	if(raiz!=NULL) {
		cola<nodo<persona>*>* artes = new cola<nodo<persona>*>; 
		cola<nodo<persona>*>* ciencias_soc = new cola<nodo<persona>*>;
		cola<nodo<persona>*>* ingenierias = new cola<nodo<persona>*>; 
		cola<nodo<persona>*>* salud = new cola<nodo<persona>*>; 
		cola<nodo<persona>*>* otros = new cola<nodo<persona>*>;
		cout<<"\nLOCALIDAD: "<<raiz->llave<<endl;
		recorrer_barrios_3(raiz->datos->barrios.getRaiz(), artes, ciencias_soc, ingenierias, salud, otros);
		nodo<persona>* aux;
		cout<<"\tArtes: ";
		while(!artes->ColaVacia()) {
			aux = artes->AtenderCola();
			cout<<" "<<aux->datos->nombre<<" "<<aux->datos->apellido<<", ";
		}
		cout<<"\n\tCiencias Sociales: ";
		while(!ciencias_soc->ColaVacia()) {
			aux = ciencias_soc->AtenderCola();
			cout<<" "<<aux->datos->nombre<<" "<<aux->datos->apellido<<", ";
		}
		cout<<"\n\tIngenierias: ";
		while(!ingenierias->ColaVacia()) {
			aux = ingenierias->AtenderCola();
			cout<<" "<<aux->datos->nombre<<" "<<aux->datos->apellido<<", ";
		}
		cout<<"\n\tSalud: ";
		while(!salud->ColaVacia()) {
			aux = salud->AtenderCola();
			cout<<" "<<aux->datos->nombre<<" "<<aux->datos->apellido<<", ";
		}
		cout<<"\n\tOtros: ";
		while(!otros->ColaVacia()) {
			aux = otros->AtenderCola();
			cout<<" "<<aux->datos->nombre<<" "<<aux->datos->apellido<<", ";
		}
		cout<<endl;
		recorrer_localidades_3(raiz->izq);
		recorrer_localidades_3(raiz->der);
	}
}

// Recorre el �rbol binario en preorden, para la lista localidades de la estructura ciudad.
void recorrer_ciudades_3(nodo<ciudad>* raiz) {
	if(raiz!=NULL) {
		recorrer_localidades_3(raiz->datos->localidades.getRaiz());
		recorrer_ciudades_3(raiz->izq);
		recorrer_ciudades_3(raiz->der);
	}
}

/* 
	Recorre el �rbol binario en preorden, de la structura iglesia para determinar cuales de la iglesias,
 	tiene un n�mero de feligreses mayor a un n�mero dado por el usuario;
*/
void recorrer_iglesias(nodo<iglesia>* raiz, int num, int* contPtr/*cola<nodo<iglesia>*>* ig*/) {
	if(raiz!=NULL) {
		if(raiz->datos->personas.getNumNodos() > num) {
			//ig->InsCola(raiz);
			*contPtr+=1;
			cout<<"\tIGLESIA: "<<raiz->llave<<endl;
			cout<<"\t\tNumero de personas: "<<raiz->datos->personas.getNumNodos()<<" \n\tNombre del sacerdote: "<<raiz->datos->lider<<" \n\tLocalidad: " <<endl;
		}
		recorrer_iglesias(raiz->izq, num, contPtr/*ig*/);
		recorrer_iglesias(raiz->der, num, contPtr/*ig*/);
	}
}

/* 
	Recorre el �rbol binario en preorden, para la lista de iglesias de la estructura localidad, 
	pasando como par�metro un apuntador de entero que almacena el n�mero de iglesias totales, 
	que cumplen con la condici�n. 
*/
void recorrer_localidades_4(nodo<localidad>* raiz, int num, int* contPtr) {
	cola<nodo<iglesia>*>* ig = new cola<nodo<iglesia>*>;
	if(raiz!=NULL) {
		cout<<"LOCALIDAD: " <<raiz->llave <<endl;
		recorrer_iglesias(raiz->datos->iglesias.getRaiz(), num, contPtr/*ig*/);
		/*contPtr+=ig->getTam();
		while(!ig->ColaVacia()) {
			nodo<iglesia>* aux = ig->AtenderCola();
			cout<<"IGLESIA: "<<aux->llave<<endl;
			cout<<"\tNumero de personas: "<<aux->datos->personas.getNumNodos()<<" \n\tNombre del sacerdote: "<<aux->datos->lider<<" \n\tLocalidad: "<<raiz->llave<<endl;
		}*/
		recorrer_localidades_4(raiz->izq, num, contPtr);
		recorrer_localidades_4(raiz->der, num, contPtr);
	}
}

// Recorre el �rbol binario en preorden, para la lista localidades de la estructura ciudad.
void recorrer_ciudades_4(nodo<ciudad>* raiz, int num, int* contPtr) {
	if(raiz!=NULL) {
		recorrer_localidades_4(raiz->datos->localidades.getRaiz(), num, contPtr);
		recorrer_ciudades_4(raiz->izq, num, contPtr);
		recorrer_ciudades_4(raiz->der, num, contPtr);
	}
}

/* 
	Recorre el �rbol binario en preorden, de la estructura persona para almacenar el n�mero de hombres y de mujeres,
	que asisten a las diferentes iglesias.
*/
void recorrer_personas_5(nodo<persona>* raiz, int* hPtr, int* mPtr) {
	if(raiz!=NULL) {
		if(raiz->datos->genero == "M") {
			*hPtr+=1;
		}else {
			*mPtr+=1;
		}
		recorrer_personas_5(raiz->izq, hPtr, mPtr);
		recorrer_personas_5(raiz->der, hPtr, mPtr);
	}
}

/* 
	Recorre el �rbol binario en preorden, para la lista personas de la estructura iglesia, 
	y crea los apuntadores y variables que almacenan el n�mero de hombre y de mujeres de las diferentes iglesias.
*/
void recorrer_iglesias_5(nodo<iglesia>* raiz) {
	if(raiz!=NULL) {
		int h, m = 0;
		int* hPtr = &h; int* mPtr = &m;
		recorrer_personas_5(raiz->datos->personas.getRaiz(), hPtr, mPtr);
		cout<<"\t\tIGLESIA: "<<raiz->llave<< "  Lider: " << raiz->datos->lider <<endl;
		cout<<"\t\t\tHombres: "<<*hPtr<<endl;
		cout<<"\t\t\tMujeres: "<<*mPtr<<endl;
		recorrer_iglesias_5(raiz->izq);
		recorrer_iglesias_5(raiz->der);
	}
}

// Recorre el �rbol binario en preorden, para la lista iglesisas de la estructura localidad.
void recorrer_localidades_5(nodo<localidad>* raiz) {
	if(raiz!=NULL) {
		cout<<"\tLOCALIDAD: "<<raiz->llave<<endl;
		recorrer_iglesias_5(raiz->datos->iglesias.getRaiz());
		recorrer_localidades_5(raiz->izq);
		recorrer_localidades_5(raiz->der);
	}
}

// Recorre el �rbol binario en preorden, para la lista localidades de la estructura ciudad.
void recorrer_ciudades_5(nodo<ciudad>* raiz) {
	if(raiz!=NULL) {
		cout<<"CIUDAD: "<<raiz->llave<<endl;
		recorrer_localidades_5(raiz->datos->localidades.getRaiz());
		recorrer_ciudades_5(raiz->izq);
		recorrer_ciudades_5(raiz->der);
	}
}

// Calcula la edad de los feligreses a partir del a�o de su nacimiento hasta el a�o 2020.
int calcular_edad(string fecha) {
	string a;	
	for(int i=6;i<=fecha.length();i++) {
		a+=fecha[i];
	}
	stringstream g(a);
	int x = 0;
	g>>x;
	x = 2020 - x;
	
	return x;
}

// Recorre el �rbol binario en preorden,
void recorrer_personas_6(nodo<persona>* raiz, int cota_i, int cota_s, string actividad) {
	if(raiz!=NULL) {
		int edad = calcular_edad(raiz->datos->fechaNac);
		if((edad >= cota_i && edad <= cota_s) && (raiz->datos->labor == actividad)) {
			cout<<"\t\t"<<raiz->datos->nombre<<" "<<raiz->datos->apellido<<endl;
		}
		recorrer_personas_6(raiz->izq, cota_i, cota_s, actividad);
		recorrer_personas_6(raiz->der, cota_i, cota_s, actividad);
	}
}

// Recorre el �rbol binario en preorden,
void recorrer_iglesias_6(nodo<iglesia>* raiz, int cota_i, int cota_s, string actividad) {
	if(raiz!=NULL) {
		cout<<"\tIGLESIA: "<<raiz->llave<<endl;
		recorrer_personas_6(raiz->datos->personas.getRaiz(), cota_i, cota_s, actividad);
		recorrer_iglesias_6(raiz->izq, cota_i, cota_s, actividad);
		recorrer_iglesias_6(raiz->der, cota_i, cota_s, actividad);
	}
	cout<<endl;
}

// Recorre el �rbol binario en preorden,
void recorrer_barrios_6(nodo<barrio>* raiz, int cota_i, int cota_s, string actividad) {
	if(raiz!=NULL){
		cout<<"\tBARRIO: "<<raiz->llave<<endl;
		recorrer_personas_6(raiz->datos->personas.getRaiz(), cota_i, cota_s, actividad);
		recorrer_barrios_6(raiz->izq, cota_i, cota_s, actividad);
		recorrer_barrios_6(raiz->der, cota_i, cota_s, actividad);
	}
}

void recorrer_localidades_6(nodo<localidad>* raiz, int cota_i, int cota_s, string actividad) {
	if(raiz!=NULL) {
		cout<<"LOCALIDAD: "<<raiz->llave<<endl;
		recorrer_barrios_6(raiz->datos->barrios.getRaiz(), cota_i, cota_s, actividad);
		recorrer_iglesias_6(raiz->datos->iglesias.getRaiz(), cota_i, cota_s, actividad);
		recorrer_localidades_6(raiz->izq, cota_i, cota_s, actividad);
		recorrer_localidades_6(raiz->der, cota_i, cota_s, actividad);
	}
}

// Recorre el �rbol binario en preorden,
void recorrer_ciudades_6(nodo<ciudad>* raiz, int cota_i, int cota_s, string actividad) {
	if(raiz!=NULL) {
		recorrer_localidades_6(raiz->datos->localidades.getRaiz(), cota_i, cota_s, actividad);
		recorrer_ciudades_6(raiz->izq, cota_i, cota_s, actividad);
		recorrer_ciudades_6(raiz->der, cota_i, cota_s, actividad);
	}
}

// Escribe en el archivo iglesias.txt el registro de una iglesia con los datos ingresados por el usuario.
void crearIglesia() {
	string ciudad, localidad, barrio, nombre, lider, direccion;
	
	ofstream myfile;
	myfile.open ("iglesias.txt", ios::app);
	
	cout << "Ingrese la ciudad donde esta ubicada la iglesia: ";
	cin >> ciudad;
	cout << "Ingrese la localidad donde esta ubicada la iglesia: ";
	cin >> localidad;
	cout << "Ingrese el barrrio donde esta ubicada la iglesia: ";
	cin >> barrio;
	cout << "Ingrese el nombre de la iglesia: ";
	cin >> nombre;
	cout << "Ingrese el nombre del lider la iglesia: ";
	cin >> lider;
	cout << "Ingrese la direccion de la iglesia: ";
	cin >> direccion;
	
	myfile << endl << ciudad << " " << localidad << " " << barrio << " " << nombre << " " << lider << " " << direccion << " ";
	cout << "La iglesia ha sido creada.";
	
	myfile.close();
}

// Escribe en el archivo database.txt el registro de un feligres con los datos ingresados por el usuario.
void crearFeligres() {
	string ciudad, localidad, barrio, iglesia, documento, nombre, apellido, tipoID, genero, telCeluar, telFijo, email, fechaNac, ciudadNac, paisNac, direccion, labor;
	
	ofstream myfile;
	myfile.open ("database.txt", ios::app);
	
	cout << "Ingrese la ciudad donde reside el feligres: ";
	cin >> ciudad; 
	cout << "Ingrese la localidad donde reside el feligres: ";
	cin >> localidad; 
	cout << "Ingrese el barrio donde reside el feligres: ";
	cin >> barrio;
	cout << "Ingrese el nombre de la iglesia a donde asiste el feligres: ";
	cin>> iglesia; 
	cout << "Ingrese el numero de documento del feligres: ";
	cin >> documento; 
	cout << "Ingrese el nombre del feligres: ";
	cin >> nombre;
	cout << "Ingrese el apellido del feligres: ";
	cin >>apellido;
	cout << "Ingrese el tipo de identificacion del feligres: ";
	cin >> tipoID;
	cout << "Ingrese el genero del feligres (M o F): ";
	
	cout<< "\n\t1. Masculino";
	cout<< "\n\t2. Femenino\n";
	char op;
	cin>>op;
	switch(op) {
		case '1':
			genero = "M";
			break;
		case '2':
			genero = "F";
			break;
		default:
			genero = "M";
	}
	
	cout << "Ingrese el numero de telefono celular del feligres: ";
	cin >> telCeluar;
	cout << "Ingrese el numero del telfonon fijo del feligres: ";
	cin >> telFijo;
	cout << "Ingrese el E-mail del feligres: ";
	cin >> email;
	cout << "Ingrese la fecha de nacimiento del feligres: ";
	cin >> fechaNac;
	cout << "Ingrese la ciudad de nacimiento del feligres: ";
	cin >> ciudadNac;
	cout << "Ingrese el pais de nacimiento del feligres: ";
	cin >> paisNac;
	cout << "Ingrese la direccion de residencia del feligres: ";
	cin >> direccion;
	cout << "Ingrese la actividad laboral del feligres: ";
	
	cout<< "\n\t1. Artes";
	cout<< "\n\t2. Ingeneria";
	cout<< "\n\t3. Ciencias Sociales";
	cout<< "\n\t4. Salud";
	cout<< "\n\t5. Otros\n";
	
	cin>>op;
	switch(op) {
		case '1':
			labor = "Artes";
			break;
		case '2':
			labor = "Ingenieria";
			break;
		case '3':
			labor = "Ciencias_sociales";
			break;
		case '4':
			labor = "Salud";
			break;
		default:
			labor = "Ingenieria";
	}
	
	myfile << endl << ciudad << " " << localidad<< " " << barrio << " " << iglesia << " " << documento << " " << nombre << " " << apellido << " " << tipoID << " " << genero << " " << telCeluar << " " << telFijo << " " << email << " " << fechaNac << " " << ciudadNac << paisNac << " " << direccion << " " << labor << " ";
	
	cout<<"Ingrese la edad de los hijos del feligres (ingrese -1 para terminar)\n";
	string h;
	int i = 0;
	cout << "\tIngrese la edad del hijo numero " << i+1 <<": ";
	cin>> h;
	while(h != "-1") {
		i++;
		myfile << h << " ";
		cout << "\tIngrese la edad del hijo numero " << i+1 <<": ";
		cin>>h;
	}
	myfile << h;
	cout << "El feligres ha sido creado.";
	
	myfile.close();
}

// Elimina un registro del archivo iglesias.txt
void eliminarIglesia();

// Submen� para la eliminaci�n de registros, ubicados en los archivos iglesias.txt y database.txt
void eliminar() {
	cout<<"\tEliminar registros";
	cout<<"\n=======================================";
	cout<<"\n1. Eliminar iglesia";
	cout<<"\n2. Eliminar feligres";
	cout<<"\n0. Regresar al menu princial\n";
	
	char op;
	cin>>op;
	system("cls");
	switch(op){
		case '1':
			cout<<"Los cambios no surguiran efecto hasta que el programa sea reiniciado.";
			getch();
			break;
		case '2':
			cout<<"Los cambios no surguiran efecto hasta que el programa sea reiniciado.";
			getch();
			break;
		case '0':
			break;
		default:
			cout << "�Opcion invalida!";
	}
}

// Submen� para las consultas de registros, ubicados en los archivos iglesias.txt y database.txt
void consultas(Arbol<ciudad>* ciudades) {
	cout<<"\t\t\t\t\tConsultas";
	cout<<"\n======================================================================================================";
	cout<<"\n 1. Numero total de personas que asisten a una iglesia, clasifcados por rango de edades de los hijos";
	cout<<"\n 2. Listado de los nombres y apellidos de aquellos que tienen  un numero de hijos";
	cout<<"\n 3. Nombre y apellidos de las personas que viven en una ciudad";
	cout<<"\n 4. Numero de iglesias a las que asiste un n�mero de personas superior a un numero";
	cout<<"\n 5. Numero de hombres y el n�mero de mujeres que asisten a las diferentes iglesias";
	cout<<"\n 6. Lista de feligreses de esa edad";
	cout<<"\n 0. Rregresar al menu principal\n";
	char op;
	cin>> op;
	system("cls");
	switch(op){
		case '1':{
			string nIglesia;
			cout<<"Ingrese el nombre de la Iglesia: ";
			cin>>nIglesia;
			nodo<iglesia>* ig = find_iglesia(ciudades->getRaiz(), nIglesia);
			if(ig!=NULL){
				int rango1 = 0, rango2 = 0, rango3 = 0, rango4 = 0, rango0 = 0;
   			int* rango1Ptr = &rango1; int* rango2Ptr = &rango2; int* rango3Ptr = &rango3; int* rango4Ptr = &rango4; int* rango0Ptr = &rango0;
		   	recorrer_1(ig->datos->personas.getRaiz(), rango1Ptr, rango2Ptr, rango3Ptr, rango4Ptr, rango0Ptr);
		   	cout<< "\nrango(sin hijos): " <<rango0 <<"\nrango(0, 5): "<<rango1<<" personas. \nrango(6, 10): "<<rango2<<" personas. \nrango(11, 18): "<<rango3<<" personas. \nrango(mayor a 18): "<<rango4<<" personas."<<endl;
			}else {
				cout << "La iglesia ingresada no ha sido encontrada en la base de datos.";
			}
		   	getch();
			break;
		}
		case '2':{
			int inf = 0, sup = 0;
			cout<<"Ingrese un rango de numero de hijos:\n";
			cout<<"desde: ";
			cin>>inf;
			cout<<"\nhasta: ";
			cin>>sup;
			recorrer_ciudades(ciudades->getRaiz(), inf, sup);
			getch();
			break;
		}
		case '3':{
			cout<<"Ingrese una ciudad: ";
			string nCiudad;
			cin>>nCiudad;
			nodo<ciudad>* c = ciudades->buscar(nCiudad);
			if(c != NULL) {
				recorrer_localidades_3(c->datos->localidades.getRaiz());
			}else {
				cout << "La ciudad ingresada no ha sido encontrada.";
			}
			getch();
			break;
		}
		case '4':{
			cout<<"Ingrese un numero maximo de personas: ";
			int num;
			cin>>num;
			int num_ig = 0;
		   	int* igPtr = &num_ig;
		   	recorrer_ciudades_4(ciudades->getRaiz(), num, igPtr);
		   	cout<<"\n Numero Iglesias: "<<*igPtr<<endl;
		   	getch();
			break;
		}
		case '5':{
			recorrer_ciudades_5(ciudades->getRaiz());
			getch();
			break;
		}
		case '6':{
			int inf, sup;
			cout<<"Seleccione una actividad laboral:\n";
			cout<<"1. Artes\n";
			cout<<"2. Ciencias Sociales\n";
			cout<<"3. Ingenierias\n";
			cout<<"4. Areas de la Salud\n";
			cout<<"5. Otros\n";
			char op2;
			cin>>op2;
			string labor;
			switch(op2){
				case '1': labor = "Artes"; break;
				case '2': labor = "Ciencias_sociales"; break;
				case '3': labor = "Ingenieria"; break;
				case '4': labor = "Salud"; break;
				case '5': labor = "Otros"; break;
			}
			cout<<"Ingrese un rango de edad:\n";
			cout<<"desde: ";
			cin>>inf;
			cout<<"hasta: ";
			cin>>sup;
			recorrer_ciudades_6(ciudades->getRaiz(), inf, sup, labor);
			getch();
			break;
		}
	}
}

// Submen� para el ingreso de registros, en los archivos de iglesias.txt y database.txt
void ingresar(Arbol<ciudad>* ciudades) {
	cout<<"\tIngresar registros";
	cout<<"\n=======================================";
	cout<<"\n1. Ingresar iglesia";
	cout<<"\n2. Ingresar feligres";
	cout<<"\n0. Regresar al menu princial\n";
	
	char op;
	cin>>op;
	system("cls");
	switch(op){
		case '1':
			crearIglesia();
			cout<<"Los cambios no surguiran efecto hasta que el programa sea reiniciado.";
			getch();
			break;
		case '2':
			crearFeligres();
			cout<<"Los cambios no surguiran efecto hasta que el programa sea reiniciado.";
			getch();
			break;
		case '0':
			break;
		default:
			cout << "�Opcion invalida!";
	}
}

int main() {
	
	Arbol<ciudad>* ciudades = new Arbol<ciudad>; // crea un apuntador a un Arbol de tipo ciudad.
	ciudades = buildIglesias(ciudades); // lee del archivo iglesias.txt para crear las estructuras de iglesia.
	ciudades = buildFeligreses(ciudades); // lee del archivo iglesias.txt para crear las estructuras de persona.
	
	// Men� principal.
	char selection;
   	do {
	   	system("cls");
	   	cout<<"\tBASE DE DATOS DE LOS FELIGRESES";
	   	cout<<"\n=======================================================";
	   	cout<<"\n 1. Consultar";
	   	cout<<"\n 2. Ingresar";
	   	cout<<"\n 3. Eliminar";
	   	cout<<"\n 0. Salir\n";
	   	cin>> selection;
	   	system("cls");
	   	switch(selection){
	   		case '1':
	   			// Men� de consultas.
	   			consultas(ciudades);
	   			break;
	   		case '2':
	   			// Men� de inserciones de registros.
	   			ingresar(ciudades);
		   		break;
		   	case '3':
		   		eliminar();
		   		break;
		   	case '0':
		   		cout << "Gracias Profe Deicy, ESTE PROGRAMA ESTA PARA UN 5!!!";
		   		break;
			default:
				cout << "�Opcion invalida!";
	   }
   	
   }while(selection!='0');
   return 0;
}
