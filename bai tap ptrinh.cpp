// bai 1 
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std ;
int main() {
    double a, b, c;

    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;

    cout << fixed << setprecision(2); 
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh vo so nghiem." << endl;
            } else {
                cout << "Phuong trinh vo nghiem." << endl;
            }
        } else {
            float x = -c / b;
            cout << "Phuong trinh co nghiem duy nhat: x = " << x << endl;
        }
    } else {
        float delta = b * b - 4 * a * c;

        if (delta > 0) {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co hai nghiem phan biet:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        } else if (delta == 0) {
            float x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: x = " << x << endl;
        } else {
            cout << "Phuong trinh vo nghiem tren tap so thuc." << endl;
        }
    }

    return 0;
}