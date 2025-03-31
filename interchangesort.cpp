#include <iostream>
using namespace std ;
void interchangesort (int a[] , int n ){
	for (int i = 0 ; i<n-1 ; i++){
		for(int j = i+1 ; j<n ; j++){
			if (a[i]>a[j]){
				swap (a[i], a[j]);
			}
		}
	}
}
int main (){
	int a[1000];
	int n ; cin>>n ;
	for (int i = 0 ; i< n ; i++){
		cin>>a[i];
	}
	interchangesort (a,n);
	for(int i = 0 ; i<n ; i++){
		cout<<a[i]<<" ";
	}
	return 0 ;
}
