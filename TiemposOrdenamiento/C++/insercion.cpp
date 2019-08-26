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
		int j, v;

		auto start = std::chrono::high_resolution_clock::now();
		for(i=1; i<n; i++){
			j = i;
			v = a[j];
			while (a[j-1]>v && j>0) {
				a[j] = a[j-1];
				j--;
			}
			a[j] = v;
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

