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

int getMax(int arr[], int n) { 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void countSort(int arr[], int n, int exp) { 
    int output[n];
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

void radixsort(int arr[], int n) { 
    int m = getMax(arr, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 

int main (){
	int n = 10;
	while (n<=500){
		//creacion--------------
		int a[n];
		for(int i=0; i<n; i++){
			a[i] = n-i;
		}
		//----------------------
		//Ordenamiento----------
		StartCounter();
		radixsort(a, n);
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
