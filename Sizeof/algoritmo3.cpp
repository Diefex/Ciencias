#include<iostream>
using namespace std;

struct nodo {
	int x, y;
	nodo *sig;
};

int main(){
	int n, i;
	cout<<"sizeof(n)="<<sizeof(n)<<endl;
	cout<<"sizeof(i)="<<sizeof(i)<<endl;
	nodo *cab = NULL, *aux;
	cout<<"sizeof(cab)="<<sizeof(cab)<<endl;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		aux = new nodo;
		cout<<"sizeof(aux)="<<sizeof(aux)<<endl;
		aux -> x = i;
		aux -> y = n-i;
		aux -> sig = cab;
		cab = aux;
	}
	
	while(aux!=NULL){
		cout<<"("<<aux->x<<","<<aux->y<<")"<<endl;
		aux = aux -> sig;
	}
	
	for(aux=cab->sig;aux!=NULL;aux=aux->sig){
		delete cab;
		cab = aux;
	}
	delete cab;
}
