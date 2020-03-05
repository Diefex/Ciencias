#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <class T>
class Arbol;

template <class T>
struct nodo {
	string nombre;
	T estructura;
	nodo<T> *izq, *der;
};

template<class T>
class Arbol{
	nodo<T> *raiz;
	bool insertar(string nombre, nodo<T> *h);
	nodo<T>* buscar(string nombre, nodo<T> *h);
	bool eliminar(string nombre, nodo<T> *h);
	public:
		Arbol(){raiz = NULL;}
		bool insertar(string nombre);
		nodo<T>* buscar(string nombre);
		bool eliminar(string nombre);
};

template <class T>
bool Arbol<T>::insertar(string nombre){
	return insertar(nombre, raiz);
}

template<class T>
bool Arbol<T>::insertar(string nombre, nodo<T> *h){
	if(h == NULL){
		nodo<T> *nuevo = new nodo<T>;
		nuevo->nombre = nombre;
		nuevo->izq = nuevo->der = NULL;
		raiz = nuevo;
		return true;
	}
	if(nombre < h->nombre){
		if(h->izq == NULL){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->nombre = nombre;
			nuevo->izq = nuevo->der = NULL;
			h->izq = nuevo;
		} else {
			insertar(nombre, h->izq);
		}
	} else {
		if(h->der == NULL){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->nombre = nombre;
			nuevo->izq = nuevo->der = NULL;
			h->der = nuevo;
		} else {
			insertar(nombre, h->der);
		}
	}
	return true;
}

template <class T>
nodo<T>* Arbol<T>::buscar(string nombre){
	return buscar(nombre, raiz);
}

template <class T>
nodo<T>* Arbol<T>::buscar(string nombre, nodo<T> *h){
	if(h == NULL){
		return NULL;
	}
	if(nombre == h->nombre){
		return h;
	}
	if(nombre < h->nombre){
		return buscar(nombre, h->izq);
	} else {
		return buscar(nombre, h->der);
	}
}

#endif
