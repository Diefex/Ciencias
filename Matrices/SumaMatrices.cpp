#include <windows.h>
#include <iostream>

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

int main(){
	int n=2, m=3;
	while(n<=1024){
		int **A, **B, **C;
		
		//llenado-------------------
		A = new int*[n];
		B = new int*[n];
		for(int i=0; i<n; i++){
			A[i] = new int[m];
			B[i] = new int[m];
			for(int j=0; j<m; j++){
				A[i][j] = (i*n)+j;
				B[i][j] = (n*m)-((i*n)+j);
			}
		}
		//--------------------------
		
	    StartCounter();
	    //suma----------------------
	    C = new int*[n];
	    for(int i=0; i<n; i++){
	    	C[i] = new int[m];
			for(int j=0; j<m; j++){
				C[i][j] = A[i][j] + B[i][j];
			}
		}
	    //--------------------------
	    cout << "suma "<<n<<"x"<<m<<" Tomo: " << GetCounter() <<" ms \n \n";
	    
	    /*for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << C[i][j];
			}
			cout<<endl;
		}*/
		//Borrado------------------
		for(int i=0; i<n; i++){
			delete A[i];
			delete B[i];
			delete C[i];
		}
		delete []A;
		delete []B;
		delete []C;
		//--------------------------
		n *= 2;
		m *= 2;
		
	}
    return 0;
}
