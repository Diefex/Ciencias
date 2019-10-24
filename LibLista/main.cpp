#include <iostream>
#include "Lista.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename T>
void imprimir(Lista<T> * lista)  {
	for(int i = 0; i < lista -> tamanio_lista(); i++) {
		cout << lista -> imprimir(i) << endl;
	}
}

int main(int argc, char** argv) {
	
	Lista<char> *lista = new Lista<char>();
	
	lista -> insertar('a',0);
	lista -> insertar('b',1);
	lista -> insertar('c',2);
	lista -> insertar('d',3);
	lista -> insertar('e',4);
	
	imprimir(lista);
	
	cout << endl;
	
	lista -> eliminar(4);
	
	imprimir(lista);
	
	cout << endl;
	
	lista -> eliminar(0);
	
	imprimir(lista);
	
	return 0;
}
