#include <iostream>
#include <windows.h>

using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter(){
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    	cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

void imprimir (int a[], int N){
	for (int i=0;i<N;i++){
		cout << a[i] << " ";
	}
}

int *llenado (int a[], int N){
	for (int i=0;i<N;i++){		
		a[i] = N-1-i;
	}
	return a;
}

int *MergeLists(int list[],int start1,int end1,int start2,int end2 ){
	int finalStart = start1;
	int finalEnd = end2;
	int indexC = 0;
	int *result = new int[finalEnd+1];
	while ((start1 <= end1) && (start2 <= end2) ){
	  	if (list[start1] < list[start2]) {
     		result[indexC] = list[start1];
      		start1 = start1 + 1;
  		}
   		else{
     		result[indexC] = list[start2];
      		start2 = start2 + 1;
   		}
   		indexC = indexC + 1;
	}

	if (start1 <= end1) {
   		for (int i = start1; i<= end1;i++) {
      		result[indexC] = list[i];
      		indexC = indexC + 1;
   		}
   	}
	else{
   		for (int i = start2; i<= end2;i++) {
      		result[indexC] = list[i];
      		indexC = indexC + 1;
   		}
	}

	indexC = 0;
	for (int i = finalStart; i<= finalEnd;i++) {
   		list[i] = result[indexC];
   		indexC = indexC + 1;
	}
	return list;
}


int *MergeSort(int list[],int first,int last ){
	int middle;
	if (first < last){
   		middle = ( first + last ) / 2;
   		list = MergeSort(list, first, middle );
   		list = MergeSort(list, middle + 1, last );
   		list = MergeLists(list, first, middle, middle + 1, last );
	}
	return list;
}

int main(){
		int N = 20;
		while (N <= 500){
			int *a = new int[N];
			a = llenado(a,N);
	    	StartCounter();
			a = MergeSort(a,0,N-1);
			/*for(int i=0;i<N;i++){
				cout<<a[i]<<",";
			}*/
	    	cout << GetCounter() <<"\n"; 
	    	delete a;
	    	N = N+ 10;
		}
    return 0;
}
