#include <iostream>
#include <malloc.h>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

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


double det(double **m, int b){

    double determinante = 0, aux = 0;

    int c;

    if(b==2)
        return m[0][0]*m[1][1] - m[1][0]*m[0][1];
    else{
        for(int j=0; j<b; j++){

                double **menor = (double **)malloc(sizeof(double)*(b-1));

                for(int h=0; h<(b-1); h++) menor[h] = (double *)malloc(sizeof(double)*(b-1));

                for(int k=1; k<b; k++){

                        c = 0;

                        for(int l=0; l<b; l++){

                                if(l!=j){

                                        menor[k-1][c] = m[k][l];

                                        c++;

                                }

                        }

                }

                aux = pow(-1, 2+j)*m[0][j]*det(menor, b-1);

                determinante += aux;

                for(int q = 0; q<(b-1); q++)

                        free(menor[q]);

                free(menor);

        }

        return determinante;

    }

}



int main(){
	
	srand(time(NULL));

    int n = 1;  // n = numero de renglones = numero de columnas

	while(n<50){
	    double **m=NULL;

	    // creacion
	
	    m = (double **)malloc(sizeof(double)*n);
	
	    for(int i=0; i<n; i++) m[i]=(double *)malloc(sizeof(double)*n);
	    
	    // llenado
	    for(int y=0; y<n; y++)
	
	    for(int w=0; w<n; w++){
	    	m[y][w] = rand()%51;;
	    }
	
		StartCounter();
		//algoritmo-----------------
		det(m, n);
		//--------------------------
		cout << "Hanoi con "<<n<<" Discos Tomo: " << GetCounter() <<" seg \n \n";
	
		// Borrado
	    for(int r=0; r<n; r++) free(m[r]);
	    free(m);
	    
	    n++;
	}
    
	return 0;
}

