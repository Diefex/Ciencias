#ifndef ARBOLBIN_H
#define ARBOLBIN_H

#include "pila.h"

template <class T>
struct nodo {
	T clave;
	nodo<T> *izq, *der;
};

template <class T>
class ArbolBin {
	nodo<T> *raiz;
	
	public:
		ArbolBin(){raiz = NULL;}
		void insertar(T dato);
		void insertar(nodo<T> *nuevo_nodo, nodo<T> *nodo);
//		nodo<T> buscar(T dato);
//		nodo<T> buscarPadre(T dato);
//		void eliminar(T dato);
//		pila<T> inorden();
};

template <class T>
void ArbolBin<T>::insertar(T dato){
	nodo<T> *nuevo_nodo;
	nuevo_nodo->clave = dato;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	if(raiz == NULL){
		raiz = nuevo_nodo;
	} else {
		insertar(nuevo_nodo, raiz);
	}
}

template <class T>
void ArbolBin<T>::insertar(nodo<T> *nuevo_nodo, nodo<T> *nodo){
	if(nuevo_nodo->clave < nodo->clave){
		if(nodo->izq == NULL){
			nodo->izq = nuevo_nodo;
		} else {
			insertar(nuevo_nodo, nodo->izq);
		}
	} else {
		if(nodo->der == NULL){
			nodo->der = nuevo_nodo;
		} else {
			insertar(nuevo_nodo, nodo->der);
		}
	}
}

#endif
