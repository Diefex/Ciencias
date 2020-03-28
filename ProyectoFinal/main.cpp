#include <iostream>
#include <fstream>
#include <sstream>
#include "estructuras.h"
#include "lista.h"

using namespace std;

Arbol<ciudad> buildIglesias(Arbol<ciudad> ciudades){
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
	while(!fe.eof()) {
        fe >> dato;
        nodo<ciudad>* ciudad = ciudades.buscar(dato);
        if(ciudad == NULL){
      	  ciudad = ciudades.insertar(dato);
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
   }
   fe.close();
   
   return ciudades;
}

Arbol<ciudad> buildFeligreses(Arbol<ciudad> ciudades){
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
        nodo<ciudad>* ciudad = ciudades.buscar(dato);
        if(ciudad == NULL){
      	  	ciudad = ciudades.insertar(dato);
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

void recorrer(nodo<persona>* raiz) {
	if(raiz!=NULL) {
		cout<<raiz->datos->nombre<<endl;
		if(raiz->izq==NULL)cout<<"izqNULL\n";
		cout<<((raiz->der==NULL)?"derNULL":raiz->der->datos->nombre )<<endl;
		recorrer(raiz->izq);
		recorrer(raiz->der);
	}
}

int main() {
	
	Arbol<ciudad> ciudades;
	
	ciudades = buildIglesias(ciudades);
	ciudades = buildFeligreses(ciudades);
   
   nodo<ciudad>* c = ciudades.buscar("Bogota");
   cout<<c->llave<<endl;
   nodo<localidad>* l = c->datos->localidades.buscar("Bosa");
   cout<<l->llave<<endl;
   nodo<barrio>* b = l->datos->barrios.buscar("Recreo");
   cout<<b->llave<<endl;
   nodo<iglesia>* i = l->datos->iglesias.buscar("San_Pepe");
   cout<<i->llave<<endl;
   nodo<persona>* pe = b->datos->personas.buscar("1010052766");
   cout<<pe->llave<<endl;
   cout<<pe->datos->nombre<<endl;
   
   nodo<hijo>* h = pe->datos->hijos.buscar("0");
   int j = 0;
   cout<<"hijos: ";
   while(h != NULL) {
   		cout<< h->datos->edad<<",";
   		j++;
   		stringstream ss;
   		ss<<j;
   		string llave;
   		ss>>llave;
   		h = pe->datos->hijos.buscar(llave);
   }
   
   cout<<endl;
   nodo<iglesia>* ig = find_iglesia(ciudades.getRaiz(), "San_nicolas_de_tolentino");
   if(ig!=NULL)cout<<"iglesia: "<<ig->llave<<endl;
   
   recorrer(ig->datos->personas.getRaiz());
   
   return 0;
}
