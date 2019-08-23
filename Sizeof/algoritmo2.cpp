#include <iostream>
using namespace std;

int main(){
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
}
