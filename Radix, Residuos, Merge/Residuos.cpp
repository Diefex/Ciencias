#include <stdio.h>
#include <windows.h>
#include <iostream>
#include<stdlib.h> 


using namespace std;



/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

void intercambio(int *a, int i, int der){
	
	int x=a[i];
	a[i]=a[der];
	a[der]=x;
	
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 


inline unsigned bits (int x,int k, int j)
    {return (x>>k)&~(~0<<j);
	}


void cambioresiduos(int a[], int izq, int der, int b)
{ int i,j; int t;
   if (der>izq && b>0)
     {i= izq; j=der;
       while(j!=i)
          {while(!bits(a[i],b,1) && i<j)i++;
            while(bits(a[j],b,1) && j>i)j--;
             intercambio(a, i, j);
           }
        if (!bits(a[i],b,1)) j++;
            cambioresiduos(a, izq, j-1, b-1);
            cambioresiduos(a, j, der, b-1);
      }
}


int* llenar(int n){
	
	int *a= new int[n];
	for(int r=0; r<n; r++){
		a[(n-1)-r]=r;
	}
	
	return a;
}

int main()
{
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	

	for(int n=10; n<=500; n+=10){
		
		int *a = new int [n];
		a=llenar(n);
		
		
	  	QueryPerformanceCounter(&t_ini); //inicia conteo del tiempo ------------------------
	  	//cambioresiduos(a,0,n-1,8);
	  	mergeSort(a, 0,n-1); 
	  	QueryPerformanceCounter(&t_fin);//fin conteo del tiempo -----------------------------
	  	
		secs = performancecounter_diff(&t_fin, &t_ini);//calculo del tiempo
		printf("%.9g ms\n", secs * 1000.0);
		
		
		//para mostrar como queda arreglado el arreglo 
		/*for(int s=0; s<n; s++)
			cout<<a[s]<<"-";
		*/
		
		delete a;
		
		secs=0;
	}
	
	
  
  
  
  return 0;
}


