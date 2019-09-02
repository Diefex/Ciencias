#include <iostream>
using namespace std;

int main(){
	int n=512, m=768;
	int **A, **B;
	cout<<"se crearon"<<endl;
	A = new int*[n];
	B = new int*[n];
	for(int i=0; i<n; i++){
		A[i] = new int[m];
		B[i] = new int[m];
		cout<<"entro i: "<<i<<endl;
		for(int j=0; j<m; j++){
			cout<<"entro j: "<<j<<endl;
			A[i][j] = 1;
			B[i][j] = 1;
		}
	}
	cout<<"se llenaron";
	for(int i=0; i<n; i++){
		delete A[i];
		delete B[i];
	}
	delete []A;
	delete []B;
	cout<<"se borraron";
	/*
	int n, i ,j;
	cout<<"sizeof(n)="<<sizeof(n)<<endl;
	cout<<"sizeof(i)="<<sizeof(i)<<endl;
	cout<<"sizeof(j)="<<sizeof(j)<<endl;
	int **a;
	cout<<"sizeof(a)="<<sizeof(a)<<endl;
	
	cin>>n;
	
	a = new int*[n];
	for(i=0; i<n; i++){
		a[i] = new int[n];
		cout<<"sizeof(a["<<i<<"])"<<sizeof(a[i])<<endl;
		for(j=0; j<n; j++){
			a[i][j] = j*i;
			cout<<"sizeof(a["<<i<<"]["<<j<<"])="<<sizeof(a[i][j])<<",";
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cout<<a[i][j]<<",";
		}
		delete a[i];
	}
	delete []a;
	*/
}
