#include <iostream>
#include <stack>

using namespace std;

// Cau truc cho mot nut trong cay bieu thuc
struct Node {
    char value;
    Node* left;
    Node* right;

    Node(char v) {
        value = v;
        left = right = NULL;
    }
};

// Ham kiem tra xem ky tu co phai la toan tu khong
bool laToanTu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Ham chuyen hau to thanh cay bieu thuc
Node* hauToSangCay(string hauTo) {
    stack<Node*> st;

    for (size_t i = 0; i < hauTo.length(); i++) {
        char kyTu = hauTo[i];

        // Neu la toan hang, tao nut va day vao stack
        if (!laToanTu(kyTu)) {
            st.push(new Node(kyTu));
        }
        // Neu la toan tu, lay 2 toan hang tu stack ra lam con
        else {
            Node* node = new Node(kyTu);

            node->right = st.top();
            st.pop();

            node->left = st.top();
            st.pop();

            st.push(node);  // Ðay cay con moi vao stack
        }
    }

    return st.top();  // Goc cua cay la phan tu cuoi cung trong stack
}

// Ham duyet cay theo thu tu trung to (da kiem tra)
void duyetLNR(Node* root) {
    if (root != NULL) {
        if (laToanTu(root->value)) cout << "(";  // In dau ngoac cho bieu thuc
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
