#include <iostream>
#include <cstring>
using namespace std;

struct NhanVien {
    char MaSo[11]; // Mã số nhân viên (chuỗi tối đa 10 ký tự + 1 cho ký tự kết thúc chuỗi)
    char Ho[11];   // Họ (chuỗi tối đa 10 ký tự)
    char Ten[51];  // Tên (chuỗi tối đa 50 ký tự)
    int Phai;      // Phái (0: nữ, 1: nam)
    int ThamNien;  // Thâm niên (số nguyên dương lớn hơn hoặc bằng 0)
};

struct PhongBan {
    NhanVien aNhanVien[100]; // Mảng chứa danh sách nhân viên (tối đa 100 nhân viên)
    int SoLuong;             // Số lượng nhân viên hiện có
};void NhapPhongBan(PhongBan &pb) {
    cout << "Nhập số lượng nhân viên: ";
    cin >> pb.SoLuong;
    cin.ignore();  // Đọc bỏ ký tự '\n' còn sót lại trong bộ đệm

    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "Nhập thông tin nhân viên " << i + 1 << ":" << endl;
        cout << "Mã số: ";
        cin.getline(pb.aNhanVien[i].MaSo, 11);
        cout << "Họ: ";
        cin.getline(pb.aNhanVien[i].Ho, 11);
        cout << "Tên: ";
        cin.getline(pb.aNhanVien[i].Ten, 51);
        cout << "Phái (0: nữ, 1: nam): ";
        cin >> pb.aNhanVien[i].Phai;
        cout << "Thâm niên: ";
        cin >> pb.aNhanVien[i].ThamNien;
        cin.ignore();  // Đọc bỏ ký tự '\n'
    }
}void XuatPhongBan(PhongBan pb) {
    cout << "Thông tin phòng ban:" << endl;
    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "Mã số: " << pb.aNhanVien[i].MaSo << endl;
        cout << "Họ: " << pb.aNhanVien[i].Ho << endl;
        cout << "Tên: " << pb.aNhanVien[i].Ten << endl;
        cout << "Phái: " << (pb.aNhanVien[i].Phai == 0 ? "Nữ" : "Nam") << endl;
        cout << "Thâm niên: " << pb.aNhanVien[i].ThamNien << endl;
        cout << "-------------------------" << endl;
    }
}void DemSiSo(PhongBan ds, int &sonam, int &sonu) {
    sonam = 0;
    sonu = 0;
    for (int i = 0; i < ds.SoLuong; i++) {
        if (ds.aNhanVien[i].Phai == 0) {
            sonu++;
        } else {
            sonam++;
        }
    }
}void SapXepTangTheoThamNien(PhongBan &pb) {
    for (int i = 0; i < pb.SoLuong - 1; i++) {
        for (int j = i + 1; j < pb.SoLuong; j++) {
            if (pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien) {
                NhanVien temp = pb.aNhanVien[i];
                pb.aNhanVien[i] = pb.aNhanVien[j];
                pb.aNhanVien[j] = temp;
            }
        }
    }
}int main() {
    PhongBan pb;
    int sonam, sonu;

    // Nhập thông tin phòng ban
    NhapPhongBan(pb);

    // Xuất thông tin phòng ban
    XuatPhongBan(pb);

    // Đếm sĩ số nam, nữ
    DemSiSo(pb, sonam, sonu);
    cout << "Sĩ số nam: " << sonam << endl;
    cout << "Sĩ số nữ: " << sonu << endl;

    // Sắp xếp danh sách nhân viên theo thâm niên
    SapXepTangTheoThamNien(pb);
    cout << "Danh sách nhân viên sau khi sắp xếp theo thâm niên:" << endl;
    XuatPhongBan(pb);

    return 0;
}