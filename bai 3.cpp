//bai 03 
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int nx, ny, nz;

    cout << "Nhap so luong phan tu cua day x: ";
    cin >> nx;
    vector<int> x(nx);
    cout << "Nhap cac phan tu cua day x: ";
    for (int i = 0; i < nx; i++) {
        cin >> x[i];
    }

    cout << "Nhap so luong phan tu cua day y: ";
    cin >> ny;
    vector<int> y(ny);
    cout << "Nhap cac phan tu cua day y: ";
    for (int i = 0; i < ny; i++) {
        cin >> y[i];
    }

    cout << "Nhap so luong phan tu cua day z: ";
    cin >> nz;
    vector<int> z(nz);
    cout << "Nhap cac phan tu cua day z: ";
    for (int i = 0; i < nz; i++) {
        cin >> z[i];
    }

    unordered_set<int> set_y(y.begin(), y.end());
    unordered_set<int> set_z(z.begin(), z.end());

    cout << "Cac phan tu chung cua ba day so la: ";
    bool found = false;
    for (int val : x) {
        if (set_y.count(val) && set_z.count(val)) {
            cout << val << " ";
            found = true;
        }
    }
    if (!found) cout << "Khong co phan tu chung.";
    cout << endl;

    return 0;
}