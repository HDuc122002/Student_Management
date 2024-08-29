#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class SinhVien {
private:
    string maSV;
    string ten;
    int tuoi;
    float GPA;

public:
    SinhVien() : maSV(""), ten(""), tuoi(0), GPA(0.0) {}

    SinhVien(string maSV, string ten, int tuoi, float GPA) 
        : maSV(maSV), ten(ten), tuoi(tuoi), GPA(GPA) {}

    string getMaSV(){
        return maSV;
    }

    void setTen(string tenMoi) {
        ten = tenMoi;
    }

    void setTuoi(int tuoiMoi) {
        tuoi = tuoiMoi;
    }

    void setGPA(float GPAMoi) {
        GPA = GPAMoi;
    }

    void hienThiThongTin() {
        cout << left << setw(10) << maSV
             << setw(25) << ten
             << setw(10) << tuoi
             << setw(10) << GPA << endl;
    }
};

class QuanLySinhVien {
private:
    SinhVien* danhSachSV;
    int soLuongSV;
    int kichThuoc;

    void tangKichThuoc() {
        kichThuoc *= 2;
        SinhVien* temp = new SinhVien[kichThuoc];
        for (int i = 0; i < soLuongSV; ++i) {
            temp[i] = danhSachSV[i];
        }
        delete[] danhSachSV;
        danhSachSV = temp;
    }

public:
    QuanLySinhVien() : soLuongSV(0), kichThuoc(10) {
        danhSachSV = new SinhVien[kichThuoc];
    }

    ~QuanLySinhVien() {
        delete[] danhSachSV;
    }

    void themSinhVien(SinhVien& sv) {
        if (soLuongSV == kichThuoc) {
            tangKichThuoc();
        }
        danhSachSV[soLuongSV++] = sv;
    }

    void hienThiDanhSach() {
        cout << left << setw(10) << "Ma SV"
             << setw(25) << "Ten"
             << setw(10) << "Tuoi"
             << setw(10) << "GPA" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < soLuongSV; ++i) {
            danhSachSV[i].hienThiThongTin();
        }
    }

    SinhVien* timKiemSinhVien(string maSV) {
        for (int i = 0; i < soLuongSV; ++i) {
            if (danhSachSV[i].getMaSV() == maSV) {
                return &danhSachSV[i];
            }
        }
        return NULL;
    }

    bool suaSinhVien(string maSV, string tenMoi, int tuoiMoi, float GPAMoi) {
        SinhVien* sv = timKiemSinhVien(maSV);
        if (sv) {
            sv->setTen(tenMoi);
            sv->setTuoi(tuoiMoi);
            sv->setGPA(GPAMoi);
            return true;
        }
        return false;
    }

    bool xoaSinhVien(string maSV) {
        for (int i = 0; i < soLuongSV; ++i) {
            if (danhSachSV[i].getMaSV() == maSV) {
                for (int j = i; j < soLuongSV - 1; ++j) {
                    danhSachSV[j] = danhSachSV[j + 1];
                }
                --soLuongSV;
                return true;
            }
        }
        return false;
    }
};

int main() {
    QuanLySinhVien ql;
    int luaChon;

    do {
        system("cls");
        cout << "---------------Quan ly danh sach sinh vien----------------" << endl;
        cout << "[1] Them sinh vien moi" << endl;
        cout << "[2] Hien thi danh sach sinh vien" << endl;
        cout << "[3] Tim kiem sinh vien" << endl;
        cout << "[4] Sua thong tin sinh vien" << endl;
        cout << "[5] Xoa sinh vien" << endl;
        cout << "[6] Thoat" << endl;
        cout << "Moi ban chon lua: ";
        cin >> luaChon;

        system("cls");

        if (luaChon == 1) {
            string maSV, ten;
            int tuoi;
            float GPA;
            cout << "Nhap ma sinh vien: ";
            cin >> maSV;
            cout << "Nhap ten sinh vien: ";
            cin.ignore();
            getline(cin, ten);
            cout << "Nhap tuoi sinh vien: ";
            cin >> tuoi;
            cout << "Nhap GPA: ";
            cin >> GPA;

            SinhVien sv(maSV, ten, tuoi, GPA);
            ql.themSinhVien(sv);

        } else if (luaChon == 2) {
            ql.hienThiDanhSach();
            system("pause");

        } else if (luaChon == 3) {
            string maSV;
            cout << "Nhap ma sinh vien can tim: ";
            cin >> maSV;

            SinhVien* sv = ql.timKiemSinhVien(maSV);
            if (sv) {
                sv->hienThiThongTin();
            } else {
                cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
            }
            system("pause");

        } else if (luaChon == 4) {
            string maSV, tenMoi;
            int tuoiMoi;
            float GPAMoi;
            cout << "Nhap ma sinh vien can sua: ";
            cin >> maSV;
            cout << "Nhap ten moi: ";
            cin.ignore();
            getline(cin, tenMoi);
            cout << "Nhap tuoi moi: ";
            cin >> tuoiMoi;
            cout << "Nhap GPA moi: ";
            cin >> GPAMoi;

            if (ql.suaSinhVien(maSV, tenMoi, tuoiMoi, GPAMoi)) {
                cout << "Sua thong tin sinh vien thanh cong!" << endl;
            } else {
                cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
            }
            system("pause");

        } else if (luaChon == 5) {
            string maSV;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;

            if (ql.xoaSinhVien(maSV)) {
                cout << "Xoa sinh vien thanh cong!" << endl;
            } else {
                cout << "Khong tim thay sinh vien co ma: " << maSV << endl;
            }
            system("pause");
        }

    } while (luaChon != 6);
    
    return 0;
}

