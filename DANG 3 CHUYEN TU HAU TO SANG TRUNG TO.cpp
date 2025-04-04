#include <iostream>
#include <stack>
#include <cstdlib>  

using namespace std;

// Ham kiem tra xem ky tu co phai la toan tu khong
bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Ham thuc hien phep toan
int tinhToan(int a, int b, char toanTu) {
    switch (toanTu) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Tranh chia cho 0
        case '^': {
            int ketQua = 1;
            for (int i = 0; i < b; i++) ketQua *= a;
            return ketQua;
        }
    }
    return 0;
}

// Ham tinh gia tri cua bieu thuc hau to
int tinhHauTo(string hauTo) {
    stack<int> st;

    for (size_t i = 0; i < hauTo.length(); i++) {
        char kyTu = hauTo[i];

        // Neu là so, chuyen sang so nguyen va day vao stack
        if (kyTu >= '0' && kyTu <= '9') {
            st.push(kyTu - '0');  
        }
        // Neu la toan tu, lay hai toan hang ta stack và tính toán
        else if (laToanTu(kyTu)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int ketQua = tinhToan(a, b, kyTu);
            st.push(ketQua);
        }
    }

    return st.top();  // Giá tri cuoi cung trong stack là ket qua
}

int main() {
    string hauTo;
    cout << "Nhap bieu thuc hau to: ";
    cin >> hauTo;

    int ketQua = tinhHauTo(hauTo);
    cout << "Ket qua cua bieu thuc la: " << ketQua << endl;

    return 0;
}
