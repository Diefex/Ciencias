#include <iostream>
#include "arbolRN.h"

using namespace std;

int main(){
	Arbol<int> a;

	int m;
	cin>>m;

	for(int i=0; i<m; i++){
		a.insertar((i+1)*25);
	}
	a.insertar(180);
	nodo<int> *c;
	for(int i=0; i<m; i++){
		c = a.buscar((i+1)*25);
		cout<<c->dato<<" | "<<c->color;
		if(c->izq!=NULL)cout<<" | izq: "<<c->izq->dato;
		if(c->der!=NULL)cout<<" | der: "<<c->der->dato;
		cout<<endl;
	}
	c = a.buscar(180);
		cout<<c->dato<<" | "<<c->color;
		if(c->izq!=NULL)cout<<" | izq: "<<c->izq->dato;
		if(c->der!=NULL)cout<<" | der: "<<c->der->dato;
		cout<<endl;
	
	//a.insertar(130);
	//c = a.buscar(130);
	//cout<<c->dato<<" "<<c->color<<endl;
	
	cout<<a.getRaiz();
	
	return 0;
}
