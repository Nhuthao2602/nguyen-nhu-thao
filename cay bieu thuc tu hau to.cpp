#include <iostream>
#include <stack>

using namespace std;

// Cấu trúc cho một nút trong cây biểu thức
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char v) {
        value = v;
        left = right = NULL;
    }
};

// Hàm kiểm tra xem ký tự có phải là toán tử không
bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Hàm chuyển hậu tố thành cây biểu thức
Node* hauToSangCay(string hauTo) {
    stack<Node*> st;

    for (size_t i = 0; i < hauTo.length(); i++) {
        char kyTu = hauTo[i];

        // Nếu là toán hạng, tạo nút và đẩy vào stack
        if (!laToanTu(kyTu)) {
            st.push(new Node(kyTu));
        }
        // Nếu là toán tử, lấy 2 toán hạng từ stack ra làm con
        else {
            Node* node = new Node(kyTu);

            node->right = st.top();
            st.pop();

            node->left = st.top();
            st.pop();

            st.push(node);  // Đẩy cây con mới vào stack
        }
    }

    return st.top();  // Gốc của cây là phần tử cuối cùng trong stack
}

// Hàm duyệt cây theo thứ tự trung tố (để kiểm tra)
void duyetLNR(Node* root) {
    if (root != NULL) {
        if (laToanTu(root->value)) cout << "(";  // In dấu ngoặc cho biểu thức
        duyetLNR(root->left);
        cout << root->value;
        duyetLNR(root->right);
        if (laToanTu(root->value)) cout << ")";
    }
}

int main() {
    string hauTo;
    cout << "Nhap bieu thuc hau to: ";
    cin >> hauTo;

    Node* root = hauToSangCay(hauTo);

    cout << "Bieu thuc trung to tuong ung: ";
    duyetLNR(root);
    cout << endl;

    return 0;
}