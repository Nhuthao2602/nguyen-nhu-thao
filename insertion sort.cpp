#include <iostream>
using namespace std ;
void insertionsort(int a[],int n){
	for(int i = 1 ; i<n ; i++){
		int x = a[i],pos=i-1;
		while(pos>=0  &&   x<a[pos]){
			a[pos+1]=a[pos];
		--pos;
		}
		a[pos+1]=x;
	}
}
int main (){
	int a[1000];
	int n ;
	cout<<" moi ban nhap so ptu :";
	cin>>n;
	for(int i = 0 ; i<n ; i++){
		cin>>a[i];
	}
	insertionsort(a,n);
	for(int i = 0 ; i< n ; i++){
		cout<<a[i]<<" ";
	}
	return 0 ;
}
