#include <iostream>
#include <stack>
#include <cstdlib>  // Để sử dụng hàm atoi()

using namespace std;

// Hàm kiểm tra xem ký tự có phải là toán tử không
bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Hàm thực hiện phép toán
int tinhToan(int a, int b, char toanTu) {
    switch (toanTu) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0; // Tránh chia cho 0
        case '^': {
            int ketQua = 1;
            for (int i = 0; i < b; i++) ketQua *= a;
            return ketQua;
        }
    }
    return 0;
}

// Hàm tính giá trị của biểu thức hậu tố
int tinhHauTo(string hauTo) {
    stack<int> st;

    for (size_t i = 0; i < hauTo.length(); i++) {
        char kyTu = hauTo[i];

        // Nếu là số, chuyển sang số nguyên và đẩy vào stack
        if (kyTu >= '0' && kyTu <= '9') {
            st.push(kyTu - '0');  
        }
        // Nếu là toán tử, lấy hai toán hạng từ stack và tính toán
        else if (laToanTu(kyTu)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int ketQua = tinhToan(a, b, kyTu);
            st.push(ketQua);
        }
    }

    return st.top();  // Giá trị cuối cùng trong stack là kết quả
}

int main() {
    string hauTo;
    cout << "Nhap bieu thuc hau to: ";
    cin >> hauTo;

    int ketQua = tinhHauTo(hauTo);
    cout << "Ket qua cua bieu thuc la: " << ketQua << endl;

    return 0;
}