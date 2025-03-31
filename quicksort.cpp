#include <iostream>
using namespace std;
void QuickSort(int a[], int left, int right) {
	int pivot = a[(left + right) / 2];
	int l = left, r = right;
	do
	{
		while (a[l] < pivot) { 
			l++;
		}
		while (a[r] > pivot) { 
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}

	} while (l  <= r);
	if (left < r) {
		QuickSort(a, left, r);
	}
	if (l < right) {
		QuickSort(a, l, right);
	}


}
int main()
{
	int n = 7;
	int a[] = { 6,3,2,-3,11,55,22 };
	int left = 0;
	int right = 6;
	QuickSort(a, left, right);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

