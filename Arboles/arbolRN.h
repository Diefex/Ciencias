#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <class T>
class Arbol;

template <class T>
struct nodo {
	T dato;
	bool color = 0;
	nodo<T> *izq = NULL, *der = NULL;
};

template<class T>
class Arbol{
	nodo<T> *raiz;
	bool insertar(T dato, nodo<T> *h);
	nodo<T>* buscar(T dato, nodo<T> *h);
	bool eliminar(nodo<T> *x);
	bool fixElim(nodo<T> *x);
	nodo<T>* buscarPadre(nodo<T> *x, nodo<T> *p);
	public:
		Arbol(){raiz = NULL;}
		T getRaiz(){return raiz->dato;}
		bool insertar(T dato);
		nodo<T>* buscar(T dato);
		bool eliminar(T dato);
		void fixIns(nodo<T> *x);
		nodo<T>* buscarPadre(nodo<T> *x);
		void rot_der(nodo<T> *p);
		void rot_izq(nodo<T> *p);
		void destruir(nodo<T> *p);
		~Arbol();
};

template <class T>
bool Arbol<T>::insertar(T dato){
	return insertar(dato, raiz);
}

template<class T>
bool Arbol<T>::insertar(T dato, nodo<T> *h){
	if(h == NULL){
		nodo<T> *nuevo = new nodo<T>;
		nuevo->dato = dato;
		nuevo->color = 0;
		raiz = nuevo;
		return true;
	}
	if(dato < h->dato){
		if(h->izq == NULL){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->dato = dato;
			nuevo->color = 1;
			h->izq = nuevo;
			fixIns(nuevo);
		} else {
			insertar(dato, h->izq);
		}
	} else {
		if(h->der == NULL){
			nodo<T> *nuevo = new nodo<T>;
			nuevo->dato = dato;
			nuevo->color = 1;
			h->der = nuevo;
			fixIns(nuevo);
		} else {
			insertar(dato, h->der);
		}
	}
	return true;
}

template <class T>
bool Arbol<T>::eliminar(T dato){
	eliminar(buscar(dato));
}

template <class T>
bool Arbol<T>::eliminar(nodo<T> *x){
	fixElim(x);
	nodo<T> *r = x;
	if(x->izq != NULL && x->der != NULL){
		x=x->der;
		while(x->izq!=NULL)x->izq;
		r->dato = x->dato;
		eliminar(x);
		return true;
	}
	
	if(x->izq!=NULL && x->der==NULL){
		x = x->izq;
	} else if (x->izq==NULL && x->der!=NULL){
		x = x->der;
	} else {
		x = NULL;
	}
	
	nodo<T> *p = buscarPadre(r);
	if(p!=NULL){
		if(p->izq == r)p->izq = x; else p->der = x;
		cout<<"eliminando, p: "<<p->dato<<endl;
		if(x==NULL)cout<<"x nulo"<<endl;
	} else {
		raiz = x;
	}
	
	return true;
	
}

template <class T>
bool Arbol<T>::fixElim(nodo<T> *x){
	nodo<T> *w;
	while(x!=raiz && !x->color){
		nodo<T> *p = buscarPadre(x);
		if(x == p->izq) {
			w = p->der;
			if(w!=NULL && w->color){
				w->color = 0;
				p->color = 1;
				rot_izq(p);
				w = p->der;
			}
			if((w->izq==NULL && w->der==NULL)||((w->izq!=NULL && w->der!=NULL)&&(!w->izq->color && !w->der->color))){
				w->color = 1;
				x = p;
			} else {
				if(w->der==NULL || !w->der->color){
					w->izq->color = 0;
					w->color = 1;
					rot_der(w);
					w = p->der;
				}
				w->color = p->color;
				p->color = 0;
				w->der->color = 0;
				rot_izq(p);
				x = raiz;
			}
		} else {
			w = p->izq;
			if(w!=NULL && w->color){
				w->color = 0;
				p->color = 1;
				rot_der(p);
				w = p->izq;
			}
			if((w->der==NULL && w->izq==NULL)||(!w->der->color && !w->izq->color)){
				w->color = 1;
				x = p;
			} else {
				if(w->izq==NULL || !w->izq->color){
					w->der->color = 0;
					w->color = 1;
					rot_izq(w);
					w = p->izq;
				}
				w->color = p->color;
				p->color = 0;
				w->izq->color = 0;
				rot_der(p);
				x = raiz;
			}
		}
	}
	x->color = 0;
	return true;
}

template <class T>
nodo<T>* Arbol<T>::buscar(T dato){
	return buscar(dato, raiz);
}

template <class T>
nodo<T>* Arbol<T>::buscar(T dato, nodo<T> *h){
	if(h == NULL){
		return NULL;
	}
	if(dato == h->dato){
		return h;
	}
	if(dato < h->dato){
		return buscar(dato, h->izq);
	} else {
		return buscar(dato, h->der);
	}
	return NULL;
}

template <class T>
void Arbol<T>::fixIns(nodo<T> *x){
	if(!x->color)return;
	nodo<T> *p = buscarPadre(x);
	if(p == NULL){
		x->color = 0;
		return;
	}
	nodo<T> *h = buscarPadre(p);
	if(h == NULL)return;
	nodo<T> *t;
	if(h->der == p){
		t = h->izq;
	} else {
		t = h->der;
	}
	if(p->color && t!=NULL && t->color){
		h->color = !h->color;
		p->color = 0;
		t->color = 0;
		fixIns(h);
	} else if((t==NULL || !t->color) && p->color){
		if(h->der == t && p->der == x){
			rot_izq(p);
			p = x;
			x = x->izq;
		} else if (h->izq == t && p->izq == x) {
			rot_der(p);
			p = x;
			x = x->der;
		}
		h->color = !h->color;
		p->color = !p->color;
		if(p->der == x){
			rot_izq(h);
		} else {
			rot_der(h);
		}
		fixIns(p);
	}
}

template <class T>
nodo<T>* Arbol<T>::buscarPadre(nodo<T> *x){
	return buscarPadre(x, raiz);
}

template <class T>
nodo<T>* Arbol<T>::buscarPadre(nodo<T> *x, nodo<T> *p){
	if(p == NULL){
		return NULL;
	}
	if(x == p->izq || x == p->der){
		return p;
	}
	if(x->dato < p->dato){
		return buscarPadre(x, p->izq);
	} else {
		return buscarPadre(x, p->der);
	}
}

template <class T>
void Arbol<T>::rot_izq(nodo<T> *p) {
	nodo<T> *h;
	h=buscarPadre(p);
	nodo<T> *q = p->der;
	if(p == NULL || q == NULL)return;
	if(h != NULL){
		if(p->dato > h->dato){
			h-> der = q;	
		} else {
			h-> izq = q;
		}
	} else {
		raiz = p->der;
	}
	p->der = q->izq; 
	q->izq = p;
}

template <class T>
void Arbol<T>::rot_der(nodo<T> *p) {
	nodo<T> *h;
	h=buscarPadre(p);
	nodo<T> *q = p->izq;
	if(p == NULL || q == NULL)return;
	if(h != NULL){
		if(p->dato > h->dato){
			h-> der = q;	
		} else {
			h-> izq = q;
		}
	} else {
		raiz = p->izq;
	}
	p->izq = q->der; 
	q->der = p;
}

template <class T>
void Arbol<T>::destruir(nodo<T> *p){
if (p!=NULL){
      destruir(p->izq);
      destruir(p->der);
      delete p;
	}
}

template <class T>
Arbol<T>::~Arbol<T>() {
	destruir(raiz);
}

#endif
