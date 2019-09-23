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

    PCFreq = double(li.QuadPart);

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void hanoi(int num,char A,char C,char B){
    if(num == 1){
        //cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
    }
    else{
        hanoi(num-1,A,B,C);
        //cout<<"Mueva el bloque "<<num<<" desde "<<A<<" hasta  "<<C<<endl;
        hanoi(num-1,B,C,A);
    }
}

int main(){
	int n=15;
	while(n<=50){
		
	    StartCounter();
	    //algoritmo-----------------
		hanoi(n,'A','C','B');
	    //--------------------------
	    cout << "Hanoi con "<<n<<" Discos Tomo: " << GetCounter() <<" seg \n \n";

		n += 5;		
	}
    return 0;
}
