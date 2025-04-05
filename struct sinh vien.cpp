#include <iostream> // Thu vien nhap xuat
#include <cstring>  // Thu vien xu ly chuoi

using namespace std; // Su dung khong gian ten std

// Cau truc SinhVien
struct SinhVien {
    char hoTen[50]; // Ho ten sinh vien (50 ky tu)
    char diaChi[70]; // Dia chi (70 ky tu)
    char lop[10]; // Lop (10 ky tu)
    int khoa; // Khoa hoc (so nguyen)

    // Ham nhap thong tin sinh vien
    void nhap() {
        cout << "Nhap ho ten: "; // Nhap ho ten
        cin.ignore(); // Xoa bo nho dem
        cin.getline(hoTen, 50); // Nhap chuoi ho ten
        cout << "Nhap dia chi: "; // Nhap dia chi
        cin.getline(diaChi, 70); // Nhap chuoi dia chi
        cout << "Nhap lop: "; // Nhap lop
        cin.getline(lop, 10); // Nhap chuoi lop
        cout << "Nhap khoa: "; // Nhap khoa hoc
        cin >> khoa; // Nhap so nguyen khoa
    }

    // Ham xuat thong tin sinh vien
    void xuat() {
        cout << hoTen << " - " << diaChi << " - " << lop << " - " << khoa << endl; // In thong tin sinh vien
    }
};

// Ham so sanh theo ho ten
bool soSanhTen(SinhVien a, SinhVien b) {
    return strcmp(a.hoTen, b.hoTen) < 0; // So sanh theo thu tu bang chu cai
}

// Ham so sanh theo dia chi
bool soSanhDiaChi(SinhVien a, SinhVien b) {
    return strcmp(a.diaChi, b.diaChi) < 0; // So sanh theo thu tu bang chu cai
}

// Ham so sanh theo lop
bool soSanhLop(SinhVien a, SinhVien b) {
    return strcmp(a.lop, b.lop) < 0; // So sanh theo thu tu bang chu cai
}

// Ham so sanh theo khoa
bool soSanhKhoa(SinhVien a, SinhVien b) {
    return a.khoa < b.khoa; // So sanh khoa theo gia tri so
}

// Cau truc Node danh sach lien ket
struct Node {
    SinhVien data; // Dinh nghia du lieu la SinhVien
    Node* next; // Con tro den node ke tiep
};

// Lop danh sach lien ket ListSV
class ListSV {
private:
    Node* head; // Con tro dau danh sach
public:
    // Ham khoi tao danh sach
    ListSV() {
        head = NULL; // Khoi tao danh sach rong
    }

    // Ham huy danh sach
    ~ListSV() {
        Node* temp; // Con tro tam
        while (head != NULL) { // Lap den khi danh sach rong
            temp = head; // Luu node hien tai
            head = head->next; // Di chuyen head sang node ke tiep
            delete temp; // Giai phong bo nho
        }
    }

    // Ham them sinh vien vao danh sach
    void themSV(SinhVien sv) {
        Node* newNode = new Node; // Cap phat bo nho cho node moi
        newNode->data = sv; // Gan du lieu cho node moi
        newNode->next = head; // Gan node moi vao dau danh sach
        head = newNode; // Cap nhat head la node moi
    }

    // Ham xoa sinh vien theo ho ten
    void xoaSVTheoTen(const char* ten) {
        Node* temp = head; // Con tro tam
        Node* prev = NULL; // Con tro truoc node hien tai

        while (temp != NULL) { // Lap den khi het danh sach
            if (strcmp(temp->data.hoTen, ten) == 0) { // Neu tim thay ten
                if (prev == NULL) { // Neu la node dau tien
                    head = temp->next; // Cap nhat head
                } else {
                    prev->next = temp->next; // Bo qua node hien tai
                }
                delete temp; // Xoa node
                return; // Dung ham
            }
            prev = temp; // Luu node truoc
            temp = temp->next; // Chuyen sang node ke tiep
        }
    }

    // Ham xoa sinh vien theo dia chi
    void xoaSVTheoDiaChi(const char* diaChi) {
        Node* temp = head; // Con tro tam
        Node* prev = NULL; // Con tro truoc node hien tai

        while (temp != NULL) { // Lap den khi het danh sach
            if (strcmp(temp->data.diaChi, diaChi) == 0) { // Neu tim thay dia chi
                if (prev == NULL) { // Neu la node dau tien
                    head = temp->next; // Cap nhat head
                } else {
                    prev->next = temp->next; // Bo qua node hien tai
                }
                delete temp; // Xoa node
                return; // Dung ham
            }
            prev = temp; // Luu node truoc
            temp = temp->next; // Chuyen sang node ke tiep
        }
    }

    // Ham xuat danh sach sinh vien
    void xuatDS() {
        Node* temp = head; // Con tro tam
        while (temp != NULL) { // Lap den khi het danh sach
            temp->data.xuat(); // Xuat thong tin sinh vien
            temp = temp->next; // Chuyen sang node ke tiep
        }
    }

    // Ham sap xep danh sach bang Selection Sort
    void sapXep(bool (*cmp)(SinhVien, SinhVien)) {
        for (Node* i = head; i != NULL; i = i->next) { // Duyet danh sach
            Node* minNode = i; // Gia su node hien tai la nho nhat
            for (Node* j = i->next; j != NULL; j = j->next) { // Duyet cac node sau
                if (cmp(j->data, minNode->data)) { // Neu tim thay node nho hon
                    minNode = j; // Cap nhat node nho nhat
                }
            }
            // Hoan doi du lieu giua i va minNode
            SinhVien temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
};

// Ham chinh
int main() {
    ListSV ds; // Tao danh sach sinh vien

    // Nhap 10 sinh vien vao danh sach
    for (int i = 0; i < 10; i++) { // Vong lap nhap du lieu
        SinhVien sv; // Tao sinh vien moi
        cout << "Nhap sinh vien " << i + 1 << ":" << endl; // Thong bao
        sv.nhap(); // Nhap du lieu
        ds.themSV(sv); // Them sinh vien vao danh sach
    }

    // In danh sach sinh vien
    cout << "\nDanh sach sinh vien:" << endl; // Thong bao
    ds.xuatDS(); // In danh sach

    // Xoa sinh vien co ten "Nguyen Van Teo"
    ds.xoaSVTheoTen("Nguyen Van Teo");

    // Xoa sinh vien co dia chi "Nguyen Van Cu"
    ds.xoaSVTheoDiaChi("Nguyen Van Cu");

    // Them sinh vien "Tran Thi Mo" vao danh sach
    SinhVien mo = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009}; // Khoi tao sinh vien moi
    ds.themSV(mo); // Them vao danh sach

    // In lai danh sach sinh vien
    cout << "\nDanh sach sinh vien sau khi cap nhat:" << endl; // Thong bao
    ds.xuatDS(); // In danh sach

    return 0; // Ket thuc chuong trinh
}