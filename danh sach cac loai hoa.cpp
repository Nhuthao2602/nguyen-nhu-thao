#include <iostream>
#include <cstring>
using namespace std;

struct LoaiHoa {
    char Ten[51];   // Tên loại hoa
    int SoLuong;    // Số lượng có trong kho
    char DVT[21];   // Đơn vị tính
    float DonGia;   // Đơn giá
};

struct DanhSachLoaiHoa {
    LoaiHoa ds[20]; // Mảng chứa danh sách các loại hoa (tối đa 20 loại)
    int SoLuong;    // Số lượng loại hoa hiện có
};void NhapDanhSach(DanhSachLoaiHoa &ds) {
    cout << "Nhập số lượng loại hoa: ";
    cin >> ds.SoLuong;
    cin.ignore();  // Đọc bỏ ký tự '\n' còn sót lại trong bộ đệm

    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Nhập thông tin loại hoa " << i + 1 << ":" << endl;
        cout << "Tên loại: ";
        cin.getline(ds.ds[i].Ten, 51);
        cout << "Số lượng: ";
        cin >> ds.ds[i].SoLuong;
        cout << "Đơn vị tính: ";
        cin.ignore();  // Đọc bỏ ký tự '\n'
        cin.getline(ds.ds[i].DVT, 21);
        cout << "Đơn giá: ";
        cin >> ds.ds[i].DonGia;
        cin.ignore();  // Đọc bỏ ký tự '\n'
    }
}void XuatDanhSach(DanhSachLoaiHoa ds) {
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Tên loại hoa: " << ds.ds[i].Ten << endl;
        cout << "Số lượng: " << ds.ds[i].SoLuong << endl;
        cout << "Đơn vị tính: " << ds.ds[i].DVT << endl;
        cout << "Đơn giá: " << ds.ds[i].DonGia << endl;
        cout << "-------------------------" << endl;
    }
}int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.ds[i].Ten, tenloai) == 0) {
            return i;  // Trả về vị trí loại hoa trong danh sách
        }
    }
    return -1;  // Nếu không tìm thấy, trả về -1
}void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong) {
    int index = TimLoaiHoa(ds, tenloai);
    if (index != -1) {
        if (ds.ds[index].SoLuong >= soluong) {
            float total = soluong * ds.ds[index].DonGia;
            cout << "Tổng tiền: " << total << endl;
            ds.ds[index].SoLuong -= soluong;  // Giảm số lượng hoa còn lại trong kho
        } else {
            cout << "Không đủ số lượng hoa để bán!" << endl;
        }
    } else {
        cout << "Loại hoa không tồn tại!" << endl;
    }
}int main() {
    DanhSachLoaiHoa ds;
    char tenloai[51];
    int soluong;

    // Nhập danh sách các loại hoa
    NhapDanhSach(ds);

    // Xuất danh sách các loại hoa
    XuatDanhSach(ds);

    // Xử lý bán hoa cho khách hàng
    cout << "Nhập tên loại hoa: ";
    cin.getline(tenloai, 51);
    cout << "Nhập số lượng muốn mua: ";
    cin >> soluong;

    XuLyBanHoa(ds, tenloai, soluong);

    return 0;
}