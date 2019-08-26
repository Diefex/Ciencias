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
			a[i] = n-i;
		}
		
		//ordenamiento
		int j, min;

		auto start = std::chrono::high_resolution_clock::now();
		for (int i = n; i >= 0; i--) {
			for (int j = 1; j < i; j++) {
				if (a[j - 1] > a[j]) { // comparacion
					// intercambio
					int aux = a[j - 1];
					a[j - 1] = a[j];
					a[j] = aux;
				}
			}
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

