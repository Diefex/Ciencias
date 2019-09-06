#include <iostream>
#include <ctime>

using namespace std;

void shellSort (int [], int);
void printVector (int [], int);

int main() {
	int tam;
	
	cout << "Tamanio: ";
	
	cin >> tam;
	
	int a [tam];
	
	for(int i = tam; i > 0; i--) {
		a[tam - i] = i;
 	}
 	
	printVector(a, tam);
	
	shellSort (a, tam);
	
	cout << endl << endl;
	
	printVector(a, tam);
	
	return 0;
}

void shellSort (int  a[], int N) {
	
	int i, j, h, v;
	
	for(h = 0; h < N/9; h = 3*(h+1));
	for(; h > 0; h /= 3) {
		for(i = h; i < N; i += 1) {
			v = a[i]; 
			j = i;
			while(j >= h && a[j-h] > v) {
				a[j] = a[j-h];
				j -= h; 
			}
			a[j] = v;
		}
	}
}

void printVector(int a[], int tam) {
	for(int i = 0; i < tam; i++) {
		cout << a[i] << ",";
	}	
}
