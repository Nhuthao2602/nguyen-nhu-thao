#include <iostream>
using namespace std;

// Định nghĩa một nút trong danh sách liên kết
struct Node {
    int data;
    Node* next;
};

// Lớp Stack sử dụng danh sách liên kết
class LinkedStackInt {
private:
    Node* top; // Con trỏ đến phần tử đầu tiên (đỉnh ngăn xếp)

public:
    LinkedStackInt() { top = nullptr; } // Khởi tạo ngăn xếp rỗng

    bool IsEmpty() { return top == nullptr; } // Kiểm tra ngăn xếp rỗng

    void PushStack(int value) { // Thêm phần tử vào ngăn xếp
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void PopStack() { // Lấy phần tử khỏi ngăn xếp
        if (IsEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int PeekStack() { // Lấy giá trị đỉnh ngăn xếp mà không xóa
        if (IsEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    void Clear() { // Xóa toàn bộ ngăn xếp
        while (!IsEmpty()) {
            PopStack();
        }
    }

    void Display() { // Hiển thị các phần tử trong ngăn xếp
        if (IsEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedStackInt() { Clear(); } // Hàm hủy để giải phóng bộ nhớ
};

// =================== Hàm main ===================
int main() {
    LinkedStackInt stack;

    cout << "Push 10, 20, 30 vào stack...\n";
    stack.PushStack(10);
    stack.PushStack(20);
    stack.PushStack(30);
    stack.Display(); // 30 20 10

    cout << "Phần tử ở đỉnh: " << stack.PeekStack() << endl; // 30

    cout << "Pop 1 phần tử khỏi stack...\n";
    stack.PopStack();
    stack.Display(); // 20 10

    cout << "Xóa toàn bộ stack...\n";
    stack.Clear();
    stack.Display(); // Stack is empty!

    return 0;
}
