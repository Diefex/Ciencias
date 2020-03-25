#include <iostream>
#include <fstream>

#include "estructuras.h"
#include "lista.h"

using namespace std;

Lista<ciudad> buildIglesias(Lista<ciudad> ciudades){
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
		
		ig->datos = new iglesia;
		fe >> ig->datos->lider;
		fe >> ig->datos->direccion;
		ig->datos->barrio = barrio->llave;
		
		localidad->datos->iglesias.insertar(ig);
   }
   fe.close();
   
   return ciudades;
}

Lista<ciudad> buildFeligreses(Lista<ciudad> ciudades){
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
		nodo<persona>* p = new nodo<persona>;
		p->llave = dato;
		p->der = p->izq = NULL;
		
		p->datos = new persona;
		fe >> p->datos->nombre;
		fe >> p->datos->apellido;
		fe >> p->datos->tipoID;
		fe >> p->datos->genero;
		fe >> p->datos->telCelular;
		fe >> p->datos->telFijo;
		fe >> p->datos->email;
		fe >> p->datos->fechaNac;
		fe >> p->datos->ciudadNac;
		fe >> p->datos->paisNac;
		fe >> p->datos->direccion;
		fe >> p->datos->labor;
		
		barrio->datos->personas.insertar(p);
		iglesia->datos->personas.insertar(p);
   }
   fe.close();
   
   return ciudades;
}

int main() {
	
	Lista<ciudad> ciudades;
	
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
   
   return 0;
}
