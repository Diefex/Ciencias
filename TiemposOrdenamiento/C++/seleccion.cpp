#include<iostream>
#include <time.h>
#include <stdio.h>
#include <dos.h> 
#include<chrono>
using namespace std;

int main() {
	int i, n, *a;
	
	for (n=10; n<=500; n+=10){
	
		a = new int[n];
		
		//relleno
		for(i=0; i<n; i++){
			a[i] = i+1;
		}
		
		//ordenamiento
		int j, min;

		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < n - 1; i++) {
			min = i;
			for (int j = i + 1; j < n; j++) {
				if (a[j] < a[min]) { // comparacion
					min = j;
				}
			}
			// intercambio
			int aux = a[min];
			a[min] = a[i];
			a[i] = aux;
		}
		auto finish = std::chrono::high_resolution_clock::now();
		cout << "N=" <<n<<", tiempo: "; 
	    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
	    cout << endl;
	    
	}
	
	    
	//impresion
	for(i=0; i<n; i++){
		//cout<<a[i]<<",";
	}
	
	delete[] a;
}

