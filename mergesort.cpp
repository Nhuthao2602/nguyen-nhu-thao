#include <iostream>
using namespace std;

// H�m tr?n hai m?ng d� s?p x?p
int* Merge(int* a, int n1, int* b, int n2) {
    int* c = new int[n1 + n2];
    int i = 0, j = 0, dem = 0;

    // Tr?n hai m?ng theo th? t? tang d?n
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            c[dem++] = a[i++];
        }
        else {
            c[dem++] = b[j++];
        }
    }

    // Sao ch�p ph?n c�n l?i c?a m?ng a
    while (i < n1) {
        c[dem++] = a[i++];
    }

    // Sao ch�p ph?n c�n l?i c?a m?ng b
    while (j < n2) {
        c[dem++] = b[j++];
    }

    return c;
}

// H�m Merge Sort
int* Mersort(int a[], int n) {
    if (n == 1) return new int[1] {a[0]};

    int mid = n / 2;

    // Chia m?ng th�nh hai n?a
    int* mang1 = new int[mid];
    int* mang2 = new int[n - mid];

    for (int i = 0; i < mid; i++) {
        mang1[i] = a[i];
    }
    for (int i = 0; i < n - mid; i++) {
        mang2[i] = a[mid + i];
    }

    // �? quy s?p x?p hai n?a
    int* sorted1 = Mersort(mang1, mid);
    int* sorted2 = Mersort(mang2, n - mid);

    // Tr?n hai n?a d� s?p x?p
    int* result = Merge(sorted1, mid, sorted2, n - mid);

    // Gi?i ph�ng b? nh? t?m th?i
    delete[] mang1;
    delete[] mang2;
    delete[] sorted1;
    delete[] sorted2;

    return result;
}

int main() {
    int a[] = { 5, 3, 2, 1, 10 };
    int n = sizeof(a) / sizeof(a[0]);

    int* Mangsort = Mersort(a, n);

    // In k?t qu?
    for (int i = 0; i < n; i++) {
        cout << Mangsort[i] << " ";
    }

    delete[] Mangsort; // Gi?i ph�ng b? nh? d?ng

    return 0;
}

