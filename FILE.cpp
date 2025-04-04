#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm sắp xếp mảng theo yêu cầu (không dùng thư viện có sẵn)
void sapXepMang(int* a, int n) {
    vector<int> nguyenTo, khongNguyenTo;

    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) nguyenTo.push_back(a[i]);
        else khongNguyenTo.push_back(a[i]);
    }

    // Hàm Bubble Sort tự viết để sắp xếp
    auto bubbleSort = [](vector<int>& v) {
        int len = v.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
            }
        }
        };

    bubbleSort(nguyenTo);
    bubbleSort(khongNguyenTo);

    // Gộp lại mảng ban đầu
    int index = 0;
    for (int num : nguyenTo) a[index++] = num;
    for (int num : khongNguyenTo) a[index++] = num;
}

// Hàm đếm số lần xuất hiện của chuỗi x trong chuỗi s
int demSoLanXuatHien(const string& s, const string& x) {
    int dem = 0;
    size_t pos = s.find(x, 0);
    while (pos != string::npos) {
        dem++;
        pos = s.find(x, pos + x.length());
    }
    return dem;
}

// Hàm tìm từ dài nhất trong chuỗi
string timTuDaiNhat(const string& s) {
    stringstream ss(s);
    string tu, tuDaiNhat;
    while (ss >> tu) {
        if (tu.length() > tuDaiNhat.length()) tuDaiNhat = tu;
    }
    return tuDaiNhat;
}

int main() {
    ifstream fileIn("DE03.INP");
    ofstream fileOut("DE03.OUT");

    if (!fileIn || !fileOut) {
        cout << "Không thể mở file!\n";
        return 1;
    }

    int n;
    fileIn >> n;

    int* a = new int[n]; // Dùng con trỏ để cấp phát động
    for (int i = 0; i < n; i++) {
        fileIn >> a[i];
    }
    fileIn.ignore(); // Bỏ qua kí tự xuống dòng

    string s, x;
    getline(fileIn, s);
    getline(fileIn, x);

    fileIn.close();

    // In dữ liệu ra console
    cout << "Mang: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nChuoi s: " << s << "\nChuoi x: " << x << "\n";

    // Sắp xếp mảng
    sapXepMang(a, n);

    // Đếm số lần xuất hiện của x trong s
    int soLanXuatHien = demSoLanXuatHien(s, x);

    // Tìm từ dài nhất
    string tuDaiNhat = timTuDaiNhat(s);

    // In ra màn hình
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n" << soLanXuatHien << "\n" << tuDaiNhat << "\n";

    // Ghi vào file
    for (int i = 0; i < n; i++) fileOut << a[i] << " ";
    fileOut << "\n" << soLanXuatHien << "\n" << tuDaiNhat << "\n";

    fileOut.close();
    delete[] a; // Giải phóng bộ nhớ

    return 0;
}