#include "arbol_nodos.h"
main(){
	ARBOL a; NODO *p;  int i;
	cout<<"Número a insertar? (fin =999)..."<<endl;
	cin>>i;
	while(i!=999){
       if (a.ins_arbol(i)==-1) cout<<"Ya existe"<< endl;
       cout<<"Número a insertar? (fin =999)..."<<endl;
       cin>>i;
	}
	cout<<"Número a retirar (fin=999)"<<endl;
	cin>>i;
	while(i!=999){
       if (a.retira_arbol(i)==-1)cout<<"No existe"<<endl;
       cout<<"Número a retirar (fin=999)"<<endl;
       cin>>i;
	}
	cout<<"Preorden:\n";
	a.preorden(a.raiz_arbol()); cout<<"__________"<<endl;
	getch();
	cout<<"Inorden:\n";
	a.inorden(a.raiz_arbol()); cout<<"___________"<<endl;
	getch();
	cout<<"Posorden:\n";
	a.posorden(a.raiz_arbol()); cout<<"__________"<<endl;
	getch();
	
	cout<<"rotar hacia:   (derecha: d, izquierda: i)"<<endl;
	char r;
	r = getch();
	cout<<"rotar sobre:"<<endl;
	cin>>i;
	
	if(r == 'd'){
		a.rot_der(i);
	} else {
		a.rot_izq(i);
	}
	
	cout<<"Preorden:\n";
	a.preorden(a.raiz_arbol()); cout<<"__________"<<endl;
	getch();
	cout<<"Inorden:\n";
	a.inorden(a.raiz_arbol()); cout<<"___________"<<endl;
	getch();
	cout<<"Posorden:\n";
	a.posorden(a.raiz_arbol()); cout<<"__________"<<endl;
	getch();
} 
