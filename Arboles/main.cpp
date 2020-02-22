#include "arbol.h"

#include <iostream>

using namespace std;

int main(){
	
	Arbol<int> t;
	t.insertar(100);
	t.insertar(50);
	t.insertar(150);
	t.insertar(75);
	t.insertar(15);
	t.insertar(5);
	t.insertar(25);
	t.insertar(75);
	t.insertar(80);
	t.insertar(120);
	t.insertar(200);
	
	for (int i=0; i<12; i++){
		nodoA<int> n = t.getNodo(i);
		cout<<n.dato<<" "<<n.izq<<" "<<n.der<<endl;
	}
	
	return 0;
}
