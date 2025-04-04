#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Ham chuyen bieu thuc trung to sang hau to
string trungToSangHauTo(string trungTo) {
    stack<char> s;
    string hauTo = "";

    for (size_t i = 0; i < trungTo.length(); i++) {  // Su dung vong lap for truyen thong
        char kyTu = trungTo[i];

        // Neu la toan hang (chu so hoac chu cai), them vao chuoi hau to
        if ((kyTu >= '0' && kyTu <= '9') || (kyTu >= 'A' && kyTu <= 'Z') || (kyTu >= 'a' && kyTu <= 'z')) {
            hauTo += kyTu;
        }
        // Neu la dau mo ngoac, day vao stack
        else if (kyTu == '(') {
            s.push(kyTu);
        }
        // Neu la dau dang ngoac, lay cac toan tu tu stack ra cho den khi gap dau mo ngoac
        else if (kyTu == ')') {
            while (!s.empty() && s.top() != '(') {
                hauTo += s.top();
                s.pop();
            }
            s.pop();  // Loai bo dau '(' khoi stack
        }
        // Neu la toan tu, xu ly du uu tiên
        else {
            while (!s.empty() && s.top() != '(') {
                hauTo += s.top();
                s.pop();
            }
            s.push(kyTu);
        }
    }

    // Ðua cac toan tu con lai trong stack vao chuoi hau to
    while (!s.empty()) {
        hauTo += s.top();
        s.pop();
    }

    return hauTo;
}

int main() {
    string trungTo;
    cout << "Nhap bieu thuc trung to: ";
    cin >> trungTo;

    string hauTo = trungToSangHauTo(trungTo);
    cout << "Bieu thuc hau to: " << hauTo << endl;

    return 0;
}
