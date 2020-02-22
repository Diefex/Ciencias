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
nodoA<T> Arbol<T>::getNodo(int pos){
	return nodos[pos];
}

#endif
