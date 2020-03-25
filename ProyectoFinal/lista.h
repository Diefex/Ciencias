#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <class T>
class Arbol;

template <class T>
struct nodo {
	string llave;
	T* datos;
	nodo<T> *izq, *der;
};

template<class T>
class Lista{
	nodo<T> *raiz;
	nodo<T>* insertar(string llave, nodo<T> *h);
	bool insertar(nodo<T>* nuevo, nodo<T> *h);
	nodo<T>* buscar(string llave, nodo<T> *h);
	bool eliminar(string llave, nodo<T> *h);
	public:
		Lista(){raiz = NULL;}
		nodo<T>* insertar(string llave);
		bool insertar(nodo<T>* nuevo);
		nodo<T>* buscar(string llave);
		bool eliminar(string llave);
};

template <class T>
nodo<T>* Lista<T>::insertar(string llave){
	return insertar(llave, raiz);
}

template<class T>
nodo<T>* Lista<T>::insertar(string llave, nodo<T> *h){
	if(h == NULL){
		nodo<T> *nuevo = new nodo<T>;
		nuevo->llave = llave;
		nuevo->izq = nuevo->der = NULL;
		nuevo->datos = new T;
		raiz = nuevo;
		return raiz;
	}
	if(llave < h->llave){
		if(h->izq == NULL){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->llave = llave;
			nuevo->izq = nuevo->der = NULL;
			nuevo->datos = new T;
			h->izq = nuevo;
			return nuevo;
		} else {
			return insertar(llave, h->izq);
		}
	} else {
		if(h->der == NULL){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->llave = llave;
			nuevo->izq = nuevo->der = NULL;
			nuevo->datos = new T;
			h->der = nuevo;
			return nuevo;
		} else {
			return insertar(llave, h->der);
		}
	}
}

template <class T>
bool Lista<T>::insertar(nodo<T>* nuevo){
	return insertar(nuevo, raiz);
}

template<class T>
bool Lista<T>::insertar(nodo<T>* nuevo, nodo<T> *h){
	if(h == NULL){
		raiz = nuevo;
		return raiz;
	}
	if(nuevo->llave < h->llave){
		if(h->izq == NULL){
			h->izq = nuevo;
			return nuevo;
		} else {
			return insertar(nuevo, h->izq);
		}
	} else {
		if(h->der == NULL){
			h->der = nuevo;
			return nuevo;
		} else {
			return insertar(nuevo, h->der);
		}
	}
	return false;
}

template <class T>
nodo<T>* Lista<T>::buscar(string llave){
	return buscar(llave, raiz);
}

template <class T>
nodo<T>* Lista<T>::buscar(string llave, nodo<T> *h){
	if(h == NULL){
		return NULL;
	}
	if(llave == h->llave){
		return h;
	}
	if(llave < h->llave){
		return buscar(llave, h->izq);
	} else {
		return buscar(llave, h->der);
	}
}

#endif
