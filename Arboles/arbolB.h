#ifndef ARBOLB_H
#define ARBOLB_H

#include<iostream>

using namespace std;

struct nodo{int *claves;
		nodo **hijos;
		int Nclaves;
		bool hoja;
		string info;
	};

class arbolB {public :nodo *raiz;
		        int d;
	public: arbolB(int ord){d = ord;
					 raiz = crear_nodo();
					 raiz->Nclaves = 0; raiz-> hoja = true;}
		   nodo *crear_nodo();
		   nodo *get_raiz ();
		   int  dividir_nodo(nodo *actual, nodo *hermano);
		   void insertar(int clave);
		   nodo *buscar_nodo(int clave, nodo *Actual, nodo **padre);
		   int InsertarNodoNormal(int clave, nodo *Actual);
		   void InsertarNodoLleno(int clave, nodo *Actual, nodo *padre);
		   nodo *buscar_padre (int clave, nodo *Actual, nodo *padre);
		   bool borrar(int clave);
		   bool borrar_clave(int, nodo*);
		   nodo *unir_nodos(nodo* hizq, nodo*hDer, int baja);
		   nodo* buscar(int clave, nodo *Actual);
		};

nodo *arbolB::crear_nodo ()
			{nodo *nuevo = new nodo;
			 nuevo -> claves= new int[2*d-1];
			 nuevo->hijos = new nodo* [2*d];
			 nuevo->Nclaves=0;
			 nuevo->hoja=true;
			 nuevo->info = "¡¡¡SOY TU COVID-2019III!!!";
			 return nuevo;
			}

nodo *arbolB::get_raiz ()
			{return raiz;
			}
			
void arbolB::insertar (int clave)
			{nodo *padre= NULL, *Actual=raiz;
			 Actual = buscar_nodo(clave, Actual, &padre);
			 if (Actual->Nclaves<2*d-1) InsertarNodoNormal(clave, Actual);
			else InsertarNodoLleno(clave, Actual, padre);
			}

nodo *arbolB:: buscar_nodo(int clave, nodo *Actual, nodo **padre)
			{ int i=0;
			 while((i < Actual ->Nclaves) && clave > Actual->claves[i]) i++;
			 if (Actual->hoja)
				{if (Actual==raiz)
					*padre=NULL;
				 return Actual;} 	
			 else  {*padre= Actual;
				 Actual= Actual ->hijos[i];
				 return buscar_nodo(clave, Actual, padre);}
			}

int arbolB::InsertarNodoNormal(int clave, nodo *Actual)
			{int i, j;
			 i=Actual->Nclaves;
			 while((i-1)>=0 && clave< Actual->claves[i-1])
				{Actual->claves[i]=Actual->claves[i-1];
				 if (!Actual->hoja) //si el nodo no es una hoja
					Actual->hijos[i+1]=Actual->hijos[i];
				 i--;
				}
			 Actual->claves[i]=clave;
			( Actual->Nclaves)++;
			return i;
			}

void arbolB::InsertarNodoLleno( int clave, nodo *Actual, nodo *padre)
			{int pos, sube;
			 nodo *nuevo, * nivelad=NULL;
			 nuevo = crear_nodo();
			 sube = dividir_nodo(Actual, nuevo);
			 if(clave<sube){
			 	InsertarNodoNormal(clave, Actual);
			 } else {
			 	InsertarNodoNormal(clave, nuevo);
			 }
			 if(Actual != raiz && padre!=NULL && padre->Nclaves< 2*d-1)
				{pos= InsertarNodoNormal(sube, padre);
				 padre->hijos[pos]=Actual;
				 padre->hijos[pos+1]=nuevo;}
			 else	{if (Actual==raiz)
					{//cout<<"Act: "<<Actual->claves[0]<<endl;
					nivelad=crear_nodo();
					 nivelad->hoja = false;
					 nivelad->claves[0] = sube;
					 nivelad->Nclaves=1;
					 nivelad->hijos[0]= Actual;
					 nivelad->hijos[1]=nuevo;
					 raiz = nivelad;}
				 else	{nivelad=buscar_padre(padre->claves[0], raiz, nivelad);
				 //if(nivelad==NULL) cout<<"\n nivelad nulo \n";
					 InsertarNodoLleno(sube, padre, nivelad);
					 nodo *h = buscar_padre(padre->claves[0], raiz, NULL);
					 //if(h==NULL) cout<<"\n h nulo \n";
					 int i=0;
					 if(padre->Nclaves<d){
						 while(i<h->Nclaves && padre->claves[0]>h->claves[i])i++;
						 padre = h->hijos[i+1];
					}
					 
					 while(i<padre->Nclaves && sube>padre->claves[i]) i++;
					 padre->hijos[i+1]=nuevo;}
					 }
			}

int arbolB::dividir_nodo(nodo *actual, nodo *nuevo)
			{int i;
			 nuevo->hoja=actual->hoja;
			 for(i=0; i<d-1; i++)
				nuevo->claves[i]=actual->claves[i+d];
			 if(!actual->hoja)
				for (i=0; i<d; i++)
					nuevo->hijos[i]=actual->hijos[i+d];
			 nuevo->Nclaves=actual->Nclaves=d-1;
			 return actual->claves[d-1];
			}

nodo *arbolB::buscar_padre (int clave, nodo *Actual, nodo *padre)
			{int i=0;
			 if(clave == Actual->claves[0])
				 return padre;
			 else	{while(i < Actual->Nclaves && clave > Actual->claves[i]) i++;
				 padre=Actual;
				 Actual= Actual -> hijos[i];
				 return buscar_padre(clave, Actual, padre);}
			}
			
nodo * arbolB::buscar(int clave, nodo *Actual){
	int i = 0;
	while((i < Actual ->Nclaves) && (clave >= Actual->claves[i])){
		if(clave == Actual->claves[i]) return Actual;
		i++;
	}
	if(Actual->hijos[i] == NULL) return NULL;
	return buscar(clave, Actual->hijos[i]);
}

bool arbolB::borrar(int clave){
	nodo *n = buscar(clave, raiz);
	if(n->hoja){
		if(n->Nclaves<d){
			nodo *p = buscar_padre(n->claves[0], raiz, NULL);
			int i = 0;
			while(i<p->Nclaves+1 && clave>p->claves[i]) i++;
			
			if(p->hijos[i-1]!=NULL && p->hijos[i-1]->Nclaves>d-1) {
				InsertarNodoNormal(p->claves[i-1],p->hijos[i]);
				p->claves[i-1] = p->hijos[i-1]->claves[p->hijos[i-1]->Nclaves-1];
				borrar_clave(p->hijos[i-1]->claves[p->hijos[i-1]->Nclaves-1],p->hijos[i-1]);
				borrar_clave(clave,p->hijos[i]);
			}else if(p->hijos[i+1]!=NULL && p->hijos[i+1]->Nclaves>d-1){
				InsertarNodoNormal(p->claves[i],p->hijos[i]);
				p->claves[i] = p->hijos[i+1]->claves[0];
				borrar_clave(p->hijos[i+1]->claves[0],p->hijos[i+1]);
				borrar_clave(clave,p->hijos[i]);
			}else {
				if(p->hijos[i-1]==NULL){
					unir_nodos(p->hijos[i],p->hijos[i+1],p->claves[i]);
					for(int j= i+1; j<p->Nclaves; j++){
						p->hijos[j] = p->hijos[j+1];
					}
					borrar_clave(p->claves[i], p);
				} else {
					unir_nodos(p->hijos[i-1],p->hijos[i],p->claves[i-1]);
					for(int j=1; j<=i; j++){
						p->hijos[j] = p->hijos[j-1];
					}
					borrar_clave(p->claves[i-1], p);
					nodo *h = buscar_padre(p->claves[0], raiz, NULL);
					if(h->hijos[i-1]!=NULL && h->hijos[i-1]->Nclaves>d-1) {
						InsertarNodoNormal(h->claves[i-1],h->hijos[i]);
						h->claves[i-1] = h->hijos[i-1]->claves[h->hijos[i-1]->Nclaves-1];
						borrar_clave(h->hijos[i-1]->claves[h->hijos[i-1]->Nclaves-1],h->hijos[i-1]);
						p->hijos[0] = h->hijos[i-1]->hijos[h->hijos[i-1]->Nclaves+1];
					}else if(h->hijos[i+1]!=NULL && h->hijos[i+1]->Nclaves>d-1){
						InsertarNodoNormal(h->claves[i],h->hijos[i]);
						h->claves[i] = h->hijos[i+1]->claves[0];
						borrar_clave(h->hijos[i+1]->claves[0],h->hijos[i+1]);
						p->hijos[0] = h->hijos[i-1]->hijos[h->hijos[i-1]->Nclaves+1];
					}
				}
				
			}
		} else {
			borrar_clave(clave,n);
		}
	}else {
		int i = 0;
		while(i<n->Nclaves && clave>n->claves[i]) i++;
		
		nodo *reemplazo = n->hijos[i+1];
		while(!reemplazo->hoja){
			reemplazo = reemplazo->hijos[0];
		}
		
		n->claves[i] = reemplazo->claves[0];
		
		borrar(reemplazo->claves[0]);
	}
}

nodo * arbolB::unir_nodos(nodo* izq, nodo* der, int baja) {
	izq->claves[izq->Nclaves] = baja;
	for(int i=0; i<der->Nclaves; i++) {
		izq->claves[izq->Nclaves+(i+1)] = der->claves[i];
	}
	
	izq->Nclaves += der->Nclaves+1;
	
	return izq;
}

bool arbolB::borrar_clave(int clave, nodo* n){
	int i = 0;
	while(i<n->Nclaves && clave>n->claves[i]) i++;
	
	n->Nclaves--;
	
	for(i; i<n->Nclaves; i++){
		n->claves[i] = n->claves[i+1];
	}
}

#endif

