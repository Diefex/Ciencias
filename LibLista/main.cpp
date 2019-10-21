#include <iostream>
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Lista<int> *lista = new Lista<int>();
	
	cout<<lista -> lista_vacia();
	//lista -> insertar(1,0);
	//lista -> insertar(1,1);
	//lista -> insertar(1,2);
	lista -> insertar(2,1);
	lista -> insertar(1,-5);
	cout<<lista -> lista_vacia();
	
	return 0;
}
