#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include "lista.h"

struct hijo{
	int edad;
};

struct persona{
	string nombre;
	string apellido;
	string tipoID;
	string genero;
	string telCelular;
	string telFijo;
	string email;
	string fechaNac;
	string ciudadNac;
	string paisNac;
	string direccion;
	string labor;
	Arbol<hijo> hijos;
};

struct iglesia{
	string lider;
	string direccion;
	string barrio;
	Arbol<persona> personas;
};

struct barrio{
	Arbol<persona> personas;
};

struct localidad{
	Arbol<barrio> barrios;
	Arbol<iglesia> iglesias;
};

struct ciudad{
	Arbol<localidad> localidades;	
};

#endif
