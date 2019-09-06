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
	int n=20;
	while(n<=500){
		int *A, i, j, h, v;
		
		//llenado-------------------
		A = new int[n];
		for(int i=0; i<n; i++){
			A[i] = n-i;
		}
		//--------------------------
		
	    StartCounter();
	    //orden---------------------
	    for(h = 0; h < n/9; h = 3*(h+1));
		for(; h > 0; h /= 3) {
			for(i = h; i < n; i += 1) {
				v = A[i]; 
				j = i;
				while(j >= h && A[j-h] > v) {
					A[j] = A[j-h];
					j -= h; 
				}
				A[j] = v;
			}
		}
	    //--------------------------
	    cout << "orden "<<n<<" Tomo: " << GetCounter() <<" ms \n \n";
	    /*
		for(int i=0; i<n; i++){
			cout << A[i] << ",";
		}
		*/
		//Borrado------------------
		delete []A;
		//--------------------------
		n += 10;
		
	}
    return 0;
}
