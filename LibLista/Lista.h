#ifndef LISTA_H
#define LISTA_H

using namespace std;

template <class T>
struct nodo {
	nodo <T> * sig;
	T info;	
};

template <class T>
class Lista {
	nodo <T> * cab;
	int tam;
	
public:
	Lista()	{
		tam = 0; cab = NULL;
	}
	
	bool lista_vacia();
	
	int tamanio_lista();
	
	void insertar_cabeza(nodo <T> *nodo_nuevo);
	
	void insertar_cola(nodo <T> *nodo_nuevo);
	
	void insertar(T info_nueva, int pos);
	
	bool eliminar(int pos);
	
	~Lista();
	
};

template<class T>
Lista<T>::~Lista() {
	delete tam;
	delete cab;
}

template <class T>
bool Lista<T>::lista_vacia() {
	if(tam == 0)
		return true;
	else 
		return false;
}

template <class T>
int Lista<T>::tamanio_lista() {
	return tam;
}

template <class T>
void Lista<T>::insertar(T info_nueva, int pos) {
	int i;
	nodo <T> *nodo_nuevo = new nodo<T>();
	
	nodo_nuevo -> info = info_nueva;
	nodo_nuevo -> sig = NULL;
	
	if(pos <= 0)
		insertar_cabeza(nodo_nuevo);
	else if(pos > (tam-1))
		insertar_cola(nodo_nuevo);
	else {
		nodo <T> * aux;
		aux = cab;
		for(i = 0; i < pos; i++)
			aux = aux -> sig;
			
		nodo_nuevo -> sig = aux -> sig;
		aux -> sig = nodo_nuevo;
	}
	tam++;
}

template <class T>
void Lista<T>::insertar_cabeza(nodo <T> *nodo_nuevo) {
	if(cab == NULL) {
		cab = nodo_nuevo;
	}else {
		nodo_nuevo -> sig = cab;
		cab = nodo_nuevo;
	}
}

template <class T>
void Lista<T>::insertar_cola(nodo <T> *nodo_nuevo) {
	if(cab ==NULL) {
		cab = nodo_nuevo;
	}else{
		nodo <T> * aux = cab;
	for(int i =0; i < tam-1; i++)
		aux = aux -> sig;
	aux -> sig = nodo_nuevo;
	}
}

#endif
