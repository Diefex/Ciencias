#include <iostream>
#include <windows.h>

using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n" << endl;

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void intercambio(int a[], int x, int y){
	int aux = a[x];
	a[x] = a[y];
	a[y] = aux;
}

void quickSort(int a[], int izq, int der){
	
	int i, j, v;
	if (der>izq){
		v = a[der];
		i = izq-1;
		j = der;
		for (;;){
			do{i++; if(i==der)break;}while(a[i]<v);
			do{j--; if(j==izq)break;}while(a[j]>v);
			if(i>=j) break;
			intercambio(a, i, j);
		}
		intercambio(a, i, der);
		quickSort(a, izq, i-1);
		quickSort(a, i+1, der);
	}
}

int main (){
	int n;
	while (n<=500){
		//creacion--------------
		int a[n];
		for(int i=0; i<n; i++){
			a[i] = n-i;
		}
		//----------------------
		//Ordenamiento----------
		StartCounter();
		quickSort(a, 0, n-1);
		cout << "orden "<<n<<" Tomo: " << GetCounter() <<" ms \n \n";
		//----------------------
		//impresion-------------
		/*for(int i=0; i<n; i++){
			cout << a[i] <<",";
		}*/
		//----------------------
		n+=10;
	}
	return 0;
}
