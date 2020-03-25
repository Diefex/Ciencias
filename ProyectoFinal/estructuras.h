#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include "lista.h"

struct hijo{
	
};

struct persona{
	string nombre;
	string apellido;
	string tipoID;
	char genero;
	string telCelular;
	string telFijo;
	string email;
	string fechaNac;
	string ciudadNac;
	string paisNac;
	string direccion;
	string labor;
	Lista<hijo> hijos;
};

struct iglesia{
	string lider;
	string direccion;
	string barrio;
	Lista<persona> personas;
};

struct barrio{
	Lista<persona> personas;
};

struct localidad{
	Lista<barrio> barrios;
	Lista<iglesia> iglesias;
};

struct ciudad{
	Lista<localidad> localidades;	
};

#endif
