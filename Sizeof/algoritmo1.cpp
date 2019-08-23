#include <iostream>
using namespace std;

int main(){
	int n, i, j;
	cout<<"sizeof(n)="<<sizeof(n)<<endl;
	cout<<"sizeof(i)="<<sizeof(i)<<endl;
	cout<<"sizeof(j)="<<sizeof(j)<<endl;
	int *a;
	cout<<"sizeof(a)="<<sizeof(a)<<endl;
	
	cin>>n;
	
	for(i=0; i<n; i++){
		a = new int[n];
		for(j=0; j<n; j++){
			a[j]=j*i;
			cout<<"sizeof(a["<<j<<"])="<<sizeof(a[j])<<",";
			//cout<<a[j]<<",";
		}
		cout<<endl;
		delete []a;
	}
}
