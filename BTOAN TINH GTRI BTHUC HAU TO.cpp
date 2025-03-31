
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define MAX 100
using namespace std;

struct Stack {
    char a[MAX][MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top < 0;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

void push(Stack &s, const char x[]) {
    if (isFull(s)) {
        cout << "Stack day, khong the push!\n";
        return;
    }
    strncpy(s.a[++s.top], x, MAX);
}

char* pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack rong, khong the pop!\n";
        return NULL ;
    }
    return s.a[s.top--];
}

bool checkOp(const char op[]) {
    return strcmp(op, "+") == 0 || strcmp(op, "-") == 0 ||
           strcmp(op, "*") == 0 || strcmp(op, "/") == 0 ||
           strcmp(op, "^") == 0 || strcmp(op, "%") == 0;
}

void cal(char s[]) {
    Stack st;
    init(st);
    char *p = strtok(s, " ");
    int t = 0;

    while (p != NULL) {
        if (checkOp(p)) {
            if (st.top < 1) {
                cout << "Loi: Bieu thuc hau to khong hop le!\n";
                return;
            }
            int b = atoi(pop(st));
            int a = atoi(pop(st));

            if (strcmp(p, "+") == 0)
                t = a + b;
            else if (strcmp(p, "-") == 0)
                t = a - b;
            else if (strcmp(p, "*") == 0)
                t = a * b;
            else if (strcmp(p, "/") == 0) {
                if (b == 0) {
                    cout << "Loi: Chia cho 0!\n";
                    return;
                }
                t = a / b;
            } 
            else if (strcmp(p, "^") == 0)
                t = pow(a, b);
            else if (strcmp(p, "%") == 0) {
                if (b == 0) {
                    cout << "Loi: Chia cho 0!\n";
                    return;
                }
                t = a % b;
            }

            char tmp[MAX];
            sprintf(tmp, "%d", t);
            push(st, tmp);
        } else {
            push(st, p);
        }
        p = strtok(NULL, " ");
    }

    if (st.top != 0) {
        cout << "Loi: Bieu thuc hau to khong hop le!\n";
        return;
    }

    cout << "Ket qua cua bieu thuc la = " << pop(st) << endl;
}

int main() {
    char s[] = "10 2 3 + / 2 ^ 4 12 8 - % +";
    cal(s);
    return 0;
}

