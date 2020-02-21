#ifndef PILA_H     
#define PILA_H

#include <iostream>
  
template <class T>
struct nodoP{T dato;
        nodoP *sig;
       };

template <class T>
class pila{nodoP<T> *cab;
      public: pila(){cab= new nodoP<T>;
                     cab->dato=NULL;
                     cab->sig=NULL;}
             void Push( T *v);
             T* Pop();
             bool PilaVacia();
             ~pila();
      };
     
template <class T>
void pila<T>::Push(T *v){
     nodoP<T> *t = new nodoP<T>;
     t->dato=v; 
     t->sig=cab->sig;
     cab->sig= t;
     }

template <class T>
T* pila<T>::Pop(){
     T *x;
     nodoP<T> *t= cab->sig;
     cab->sig= t->sig; 
     x=t->dato;
     delete t;
     return x;
     }
     
template <class T>
bool pila<T>::PilaVacia(){
      return cab->sig== NULL;
      }

template <class T>
 pila<T>::~pila(){
      nodoP<T> *t=cab;
     while (t!=NULL){
           cab=t;
           t=t->sig;
           delete cab;
           }
     }
 
     
#endif
