#include <iostream>
#include <iomanip>
#include "arbolB.h"

using namespace std;

void impClaves(nodo *n){
	for(int i = 0; i<n->Nclaves; i++){
			cout<<n->claves[i]<<",";
		}
}

void impNiveles(nodo *Actual, int l){
	for(int i=0; i<l; i++) cout<<"    ";
	impClaves(Actual);
	cout<<endl;
	if(!Actual->hoja){
		for(int i=0; i<Actual->Nclaves+1; i++){
			if(Actual->hijos[i]==NULL){
				cout<<"hijo nulo\n";
			} else {
				impNiveles(Actual->hijos[i], l+1);
			}
			
		}
	}
}

int main(){
	
	cout<<"creando arbol B de orden 3\n";
	arbolB a(3);
	
	cout<<"insertando...\n";
	
	a.insertar(30);
	a.insertar(31);
	a.insertar(22);
	a.insertar(23);
	a.insertar(24);
	a.insertar(25);
	a.insertar(26);
	a.insertar(27);
	a.insertar(28);
	a.insertar(29);
	a.insertar(20);
	a.insertar(21);
	a.insertar(40);
	a.insertar(41);
	a.insertar(12);
	a.insertar(13);
	a.insertar(14);
	a.insertar(15);
	a.insertar(16);
	a.insertar(17);
	a.insertar(18);
	a.insertar(19);
	a.insertar(10);
	a.insertar(11);
	a.insertar(42);
	a.insertar(43);
	a.insertar(44);
	for(int i=50; i<=58; i++){
		a.insertar(i);
	}
	
	cout<<"Arbol B de orden 3\n\n";
	
	impNiveles(a.raiz, 0);
	
	cout<<"\n borrando clave 12 \n";
	a.borrar(12);
	impNiveles(a.raiz, 0);
	
	cout<<"\n borrando clave 22 \n";
	a.borrar(22);
	impNiveles(a.raiz, 0);
	
	cout<<"\n borrando clave 15 \n";
	a.borrar(15);
	impNiveles(a.raiz, 0);
	
	cout<<"\n borrando clave 53 \n";
	a.borrar(53);
	impNiveles(a.raiz, 0);
	
	cout<<"\n Informacion de la clave 24\n";
	cout<<a.buscar(24,a.raiz)->info<<endl<<endl;
	
	cout<<"---------------------"<<endl;
	
	cout<<"creando arbol B de orden 2\n";
	arbolB b(2);
	
	cout<<"insertando...\n";
	
	b.insertar(30);
	b.insertar(31);
	b.insertar(22);
	b.insertar(23);
	b.insertar(24);
	b.insertar(25);
	b.insertar(26);
	b.insertar(27);
	b.insertar(28);
	b.insertar(29);
	b.insertar(20);
	b.insertar(21);
	b.insertar(40);
	b.insertar(41);
	b.insertar(12);
	b.insertar(13);
	b.insertar(14);
	b.insertar(15);
	b.insertar(16);
	b.insertar(17);
	b.insertar(18);
	b.insertar(19);
	
	cout<<"Arbol B de orden 2\n\n";
	
	impNiveles(b.raiz, 0);
	
	cout<<"\n borrando clave 40 \n";
	b.borrar(40);
	impNiveles(b.raiz, 0);
	
	cout<<"\n borrando clave 19 \n";
	b.borrar(19);
	impNiveles(b.raiz, 0);
	
	return 0;
}

