#ifndef ARBOLB_H
#define ARBOLB_H

#include <iostream>

using namespace std;

template <class T>
struct nodo {
	string llave;
	T* datos;
	nodo<T> *izq, *der;
};

// Clase Arbol.
template<class T>
class Arbol{
	nodo<T> *raiz;
	int num_nodos;
	nodo<T>* insertar(string llave, nodo<T> *h);
	nodo<T>* insertar(nodo<T>* nuevo, nodo<T> *h);
	nodo<T>* buscar(string llave, nodo<T> *h);
	bool eliminar(string llave, nodo<T> *h);
	public:
		Arbol(){raiz = NULL; num_nodos = 0;}
		nodo<T>* insertar(string llave);
		nodo<T>* insertar(nodo<T>* nuevo);
		nodo<T>* buscar(string llave);
		bool eliminar(string llave);
		nodo<T>* getRaiz();
		int getNumNodos();
};

// Retorna la raíz de la clase Arbol.
template <class T>
nodo<T>* Arbol<T>::getRaiz() {
	return raiz;
}

/* 
	Hay dos 4 método de insertar 2 pequeños y 2 grandes, los pequeños llaman con la raíz a los nodos grandes, 
	para insertar nodos nuevos y nodos previamente creados.	
*/

// Llama al método insertar con la la raíz del árbol.
template <class T>
nodo<T>* Arbol<T>::insertar(string llave){
	num_nodos++;
	return insertar(llave, raiz);
}

// Crea un nodo y lo inserta en el árbol;
template<class T>
nodo<T>* Arbol<T>::insertar(string llave, nodo<T> *h){
	if(raiz == NULL){
		nodo<T> *nuevo = new nodo<T>;
		nuevo->llave = llave;
		nuevo->izq = nuevo->der = NULL;
		nuevo->datos = new T;
		raiz = nuevo;
		return raiz;
	}
	if(h == NULL){
		nodo<T> *nuevo = new nodo<T>;
		nuevo->llave = llave;
		nuevo->izq = nuevo->der = NULL;
		nuevo->datos = new T;
		h = nuevo;
		return h;
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

// Recibe y llama al método insertar pasando el nodo nuevo y la raíz del árbol.
template <class T>
nodo<T>* Arbol<T>::insertar(nodo<T>* nuevo){
	num_nodos++;
	return insertar(nuevo, raiz);
}

// Recibe un nodo y lo inserta.
template<class T>
nodo<T>* Arbol<T>::insertar(nodo<T>* nuevo, nodo<T> *h){
	if(raiz==NULL){
		raiz = nuevo;
		return raiz;
	}
	if(h == NULL){
		h = nuevo;
		return h;
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
	
}

// Llama al método buscar pasándole la llave.
template <class T>
nodo<T>* Arbol<T>::buscar(string llave){
	return buscar(llave, raiz);
}

// Busca un nodo del árbol con la llave desde un nodo dado.
template <class T>
nodo<T>* Arbol<T>::buscar(string llave, nodo<T> *h){
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

// Retorno el número de nodos del árbol;
template <class T>
int Arbol<T>::getNumNodos() {
	return num_nodos;
}

#endif
