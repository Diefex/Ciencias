#include <cstdlib>
#include <iostream>

#ifndef COLA1_H     
#define COLA1_H 

using namespace std;

template<class T>
struct nodo_cola{T dato;
        nodo_cola *sig;
};

template<class T>
class cola{nodo_cola<T> *cab,*fin; int tam;
      public: cola(){cab=fin=NULL;}
      void InsCola(T i);
      T AtenderCola();
      void ImprimirCola();
      bool ColaVacia();
      int getTam();
      ~cola();
 };

template<class T>
void cola<T>::InsCola(T i){
     nodo_cola<T> *nuevo;
     nuevo= new nodo_cola<T>;
     nuevo->dato=i;
     nuevo->sig= NULL;
     if (cab==NULL)
         {cab=nuevo;}
     else {fin->sig = nuevo;}
     fin=nuevo;
     tam++;
}


template<class T>
T cola<T>::AtenderCola()
{   T x;
    nodo_cola<T> *aux = cab; 
    cab=aux->sig;
    x=aux->dato;
    delete aux;
    tam--;
    return x;
    }

template<class T>
void cola<T>::ImprimirCola(){
     nodo_cola<T> *aux;
     aux=cab;
     while(aux!=NULL){
       cout<<aux->dato<<" ";
       aux=aux->sig;}    
}

template<class T>
bool cola<T>::ColaVacia(){
     return (cab==NULL);
     }

template<class T>
cola<T>::~cola(){
     nodo_cola<T> *aux;
     while(cab!=NULL)
       {aux= cab;
        cab=aux->sig;
        delete aux;}
     delete cab;
}

template<class T>
int cola<T>::getTam() {
	return tam;
}

#endif

