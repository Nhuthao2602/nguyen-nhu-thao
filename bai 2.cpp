//bai 02 
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

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
            double x2 = -c / b;
            if (x2 >=0){
                if(x2 == 0) cout << "Phuong trinh co nghiem duy nhat x = 0" << endl;
                else cout << "Phuong trinh co hai nghiem x = " << sqrt(x2) << " va x = " << -sqrt(x2) << endl;
            }
            else cout << "Phuong trinh vo nghiem" << endl;
        }
    } else {
        double delta = b * b - 4 * a * c;

        if (delta > 0) {
            double t1 = (-b + sqrt(delta)) / (2 * a);
            double t2 = (-b - sqrt(delta)) / (2 * a);
            if (t1 > 0 && t2 > 0) {
                cout << "Phuong trinh co bon nghiem phan biet:" << endl;
                cout << "x1 = " << sqrt(t1) << endl;
                cout << "x2 = " << -sqrt(t1) << endl;
                cout << "x3 = " << sqrt(t2) << endl;
                cout << "x4 = " << -sqrt(t2) << endl;
            } else if (t1 > 0 && t2 <= 0) {
                cout << "Phuong trinh co hai nghiem phan biet:" << endl;
                cout << "x1 = " << sqrt(t1) << endl;
                cout << "x2 = " << -sqrt(t1) << endl;
            } else if (t1 <= 0 && t2 > 0) {
                cout << "Phuong trinh co hai nghiem phan biet:" << endl;
                cout << "x1 = " << sqrt(t2) << endl;
                cout << "x2 = " << -sqrt(t2) << endl;
            }
            else cout << "Phuong trinh vo nghiem." << endl;
        } else if (delta == 0) {
            double t = -b / (2 * a);
            if(t > 0){
                cout << "Phuong trinh co hai nghiem kep:" << endl;
                cout << "x1 = " << sqrt(t) << endl;
                cout << "x2 = " << -sqrt(t) << endl;
            }
            else if (t == 0) cout << "Phuong trinh co nghiem duy nhat x = 0" << endl;
            else cout << "Phuong trinh vo nghiem." << endl;
        } else {
            cout << "Phuong trinh vo nghiem." << endl;
        }
    }

    return 0;
}