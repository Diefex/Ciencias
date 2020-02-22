#ifndef ARBOL_H
#define ARBOL_H

template <class T>
struct nodoA{
	T dato;
	int der, izq;
};

template <class T>
class Arbol{
	nodoA<T> nodos[50];
	public:
		Arbol(){
			for(int i=0; i<49; i++) nodos[i].der = i+1;
			nodos[49].der = 0;
			nodos[0].izq = 0;
		}
		
		void insertar(T dato);
		int buscar(T dato);
		int buscarPadre(T dato);
		void eliminar(T dato);
		nodoA<T> getNodo(int pos);
};

template<class T>
void Arbol<T>::insertar(T dato){
	int pos = nodos[0].der;
	nodos[0].der = nodos[pos].der;
	nodos[pos].dato = dato;
	nodos[pos].izq = 0;
	nodos[pos].der = 0;
	
	int i = nodos[0].izq;
	int aux = i;
	while(i!=0){
		aux = i;
		if(dato < nodos[i].dato){
			i = nodos[i].izq;
		} else {
			i = nodos[i].der;
		}
	}
	
	if(dato < nodos[aux].dato || aux == 0){
		nodos[aux].izq = pos;
	} else {
		nodos[aux].der = pos;
	}
}

template <class T>
int Arbol<T>::buscar(T dato){
	int i = nodos[0].izq;
	do{
		if(dato < nodos[i].dato){
			i = nodos[i].izq;
		} else {
			i = nodos[i].der;
		}
	}while(dato!=nodos[i].dato);
	return i;
}

template <class T>
int Arbol<T>::buscarPadre(T dato){
	int i = nodos[0].izq;
	int aux = i;
	do{
		aux = i;
		if(dato < nodos[i].dato){
			i = nodos[i].izq;
		} else {
			i = nodos[i].der;
		}
	}while(dato!=nodos[i].dato);
	return aux;
}

template <class T>
void Arbol<T>::eliminar(T dato){
	int aux = buscar(dato);
	if(nodos[aux].izq == 0 && nodos[aux].der == 0){
		int padre = buscarPadre(nodos[aux].dato);
		if(nodos[aux].dato < nodos[padre].dato){
			nodos[padre].izq = 0;
		} else {
			nodos[padre].der = 0;
		}
		nodos[aux].der = nodos[0].der;
		nodos[0].der = aux;
	}
	if(nodos[aux].izq != 0 && nodos[aux].der == 0){
		int padre = buscarPadre(nodos[aux].dato);
		if(nodos[aux].dato < nodos[padre].dato){
			nodos[padre].izq = nodos[aux].izq;
		} else {
			nodos[padre].der = nodos[aux].izq;
		}
		nodos[aux].der = nodos[0].der;
		nodos[0].der = aux;
	}
	if(nodos[aux].izq == 0 && nodos[aux].der != 0){
		int padre = buscarPadre(nodos[aux].dato);
		if(nodos[aux].dato < nodos[padre].dato){
			nodos[padre].izq = nodos[aux].der;
		} else {
			nodos[padre].der = nodos[aux].der;
		}
		nodos[aux].der = nodos[0].der;
		nodos[0].der = aux;
	}
	if(nodos[aux].izq != 0 && nodos[aux].der != 0){
		int i = aux;
		while(nodos[nodos[i].izq].izq!=0){
			i = nodos[i].izq;
		}
		i = nodos[i].der;
		int padre = buscarPadre(nodos[i].dato);
		if(nodos[i].dato < nodos[padre].dato){
			nodos[padre].izq = 0;
		} else {
			nodos[padre].der = 0;
		}
		nodos[aux].dato = nodos[i].dato;
		nodos[i].der = nodos[0].der;
		nodos[0].der = i;
	}
}

template <class T>
nodoA<T> Arbol<T>::getNodo(int pos){
	return nodos[pos];
}

#endif
