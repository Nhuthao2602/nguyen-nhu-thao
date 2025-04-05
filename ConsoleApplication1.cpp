//tim phan tu lon nhat trong danh sach a co n phan tu 
#include <iostream>
using namespace std;
int timmax(int a[], int first, int last) {
	//base case : danh sach co 1 phan tu 
	int max;
	if (first == last) {
		return a[first];
	}
	//genaral case last>first (n>1)
	int m = timmax(a, first + 1, last);
	if (m < a[first]) {
		m = a[first];
	}
	return m;
}
int main() {
	int a[] = { 4,5,2,7,9,3 };
	int m = timmax(a, 0, 5);
	cout << " max = " << m << endl;
	return 0;
}