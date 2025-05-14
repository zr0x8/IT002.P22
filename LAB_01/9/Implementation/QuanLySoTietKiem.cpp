#include "QuanLySoTietKiem.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

void QuanLySoTietKiem::themSo() {
    SoTietKiem so;
    so.nhapThongTin();
    danhSachSo.push_back(so);
    cout << "Da them so tiet kiem thanh cong!\n";
}

void QuanLySoTietKiem::xuatDanhSach() const {
    if (danhSachSo.empty()) {
        cout << "Danh sach so tiet kiem rong.\n";
        return;
    }
    
    cout << setw(10) << left << "Ma so"
         << setw(15) << left << "Loai tiet kiem"
         << setw(35) << left << "Ho ten khach hang"
         << setw(15) << left << "CMND"
         << setw(12) << left << "Ngay mo so"
         << setw(15) << right << "So tien gui" << endl;
    
    cout << string(102, '-') << endl;
    
    for (const auto& so : danhSachSo) {
        so.xuatThongTin();
    }
}

void QuanLySoTietKiem::tinhLaiSuat() {
    if (danhSachSo.empty()) {
        cout << "Danh sach so tiet kiem rong.\n";
        return;
    }
    
    string maSo;
    cout << "Nhap ma so tiet kiem can tinh lai: ";
    cin >> maSo;
    
    SoTietKiem* so = timSoTheoMaSo(maSo);
    
    if (!so) {
        cout << "Khong tim thay so tiet kiem voi ma so " << maSo << ".\n";
        return;
    }
    
    double laiSuat;
    cout << "Nhap lai suat (%/nam): ";
    cin >> laiSuat;
    
    int soNgay = so->tinhSoNgayGuiTien();
    double tienLai = so->tinhTienLai(laiSuat, soNgay);
    
    cout << "Thong tin so tiet kiem:\n";
    cout << setw(10) << left << "Ma so"
         << setw(15) << left << "Loai tiet kiem"
         << setw(35) << left << "Ho ten khach hang"
         << setw(15) << left << "CMND"
         << setw(12) << left << "Ngay mo so"
         << setw(15) << right << "So tien gui" << endl;
    
    cout << string(102, '-') << endl;
    so->xuatThongTin();
    
    cout << "\nSo ngay gui tien: " << soNgay << " ngay\n";
    cout << "Tien lai: " << fixed << setprecision(2) << tienLai << endl;
    cout << "Tong tien (goc + lai): " << fixed << setprecision(2) 
         << (so->getSoTienGui() + tienLai) << endl;
}

void QuanLySoTietKiem::rutTien() {
    if (danhSachSo.empty()) {
        cout << "Danh sach so tiet kiem rong.\n";
        return;
    }
    
    string maSo;
    cout << "Nhap ma so tiet kiem can rut tien: ";
    cin >> maSo;
    
    SoTietKiem* so = timSoTheoMaSo(maSo);
    
    if (!so) {
        cout << "Khong tim thay so tiet kiem voi ma so " << maSo << ".\n";
        return;
    }
    
    cout << "So tien gui hien tai: " << fixed << setprecision(2) << so->getSoTienGui() << endl;
    
    double soTienRut;
    cout << "Nhap so tien muon rut: ";
    cin >> soTienRut;
    
    double laiSuatTruocHan = 0.5;
    
    so->rutTien(soTienRut, laiSuatTruocHan);
}

SoTietKiem* QuanLySoTietKiem::timSoTheoCMND(long cmnd) {
    for (auto& so : danhSachSo) {
        if (so.getCMND() == cmnd) {
            return &so;
        }
    }
    return nullptr;
}

SoTietKiem* QuanLySoTietKiem::timSoTheoMaSo(const string& maSo) {
    for (auto& so : danhSachSo) {
        if (so.getMaSo() == maSo) {
            return &so;
        }
    }
    return nullptr;
}

bool isDateInRange(const SoTietKiem& so, 
                  int ngayBatDau, int thangBatDau, int namBatDau,
                  int ngayKetThuc, int thangKetThuc, int namKetThuc) {
    int dateSo = so.getNamMoSo() * 10000 + so.getThangMoSo() * 100 + so.getNgayMoSo();
    int dateStart = namBatDau * 10000 + thangBatDau * 100 + ngayBatDau;
    int dateEnd = namKetThuc * 10000 + thangKetThuc * 100 + ngayKetThuc;
    
    return (dateSo >= dateStart && dateSo <= dateEnd);
}

void QuanLySoTietKiem::lietKeSoTheoKhoangThoiGian(int ngayBatDau, int thangBatDau, int namBatDau, 
                                                 int ngayKetThuc, int thangKetThuc, int namKetThuc) {
    bool found = false;
    
    cout << setw(10) << left << "Ma so"
         << setw(15) << left << "Loai tiet kiem"
         << setw(35) << left << "Ho ten khach hang"
         << setw(15) << left << "CMND"
         << setw(12) << left << "Ngay mo so"
         << setw(15) << right << "So tien gui" << endl;
    
    cout << string(102, '-') << endl;
    
    for (const auto& so : danhSachSo) {
        if (isDateInRange(so, ngayBatDau, thangBatDau, namBatDau, ngayKetThuc, thangKetThuc, namKetThuc)) {
            so.xuatThongTin();
            found = true;
        }
    }
    
    if (!found) {
        cout << "Khong tim thay so tiet kiem nao trong khoang thoi gian nay.\n";
    }
}

void QuanLySoTietKiem::sapXepTheoSoTienGiamDan() {
    if (danhSachSo.empty()) {
        cout << "Danh sach so tiet kiem rong.\n";
        return;
    }
    
    sort(danhSachSo.begin(), danhSachSo.end(), 
         [](const SoTietKiem& a, const SoTietKiem& b) {
             return a.getSoTienGui() > b.getSoTienGui();
         });
    
    cout << "Da sap xep danh sach theo so tien gui giam dan.\n";
    xuatDanhSach();
}

void QuanLySoTietKiem::sapXepTheoNgayMoSoTangDan() {
    if (danhSachSo.empty()) {
        cout << "Danh sach so tiet kiem rong.\n";
        return;
    }
    
    sort(danhSachSo.begin(), danhSachSo.end(), 
         [](const SoTietKiem& a, const SoTietKiem& b) {
             if (a.getNamMoSo() != b.getNamMoSo()) {
                 return a.getNamMoSo() < b.getNamMoSo();
             }
             if (a.getThangMoSo() != b.getThangMoSo()) {
                 return a.getThangMoSo() < b.getThangMoSo();
             }
             return a.getNgayMoSo() < b.getNgayMoSo();
         });
    
    cout << "Da sap xep danh sach theo ngay mo so tang dan.\n";
    xuatDanhSach();
}

void QuanLySoTietKiem::menu() {
    int choice;
    do {
        cout << "\n=== CHUONG TRINH QUAN LY SO TIET KIEM ===\n";
        cout << "1. Them so tiet kiem moi\n";
        cout << "2. Xuat danh sach so tiet kiem\n";
        cout << "3. Tinh tien lai\n";
        cout << "4. Rut tien\n";
        cout << "5. Tim so tiet kiem theo CMND\n";
        cout << "6. Tim so tiet kiem theo ma so\n";
        cout << "7. Liet ke so tiet kiem theo khoang thoi gian\n";
        cout << "8. Sap xep danh sach theo so tien giam dan\n";
        cout << "9. Sap xep danh sach theo ngay mo so tang dan\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                themSo();
                break;
            case 2:
                xuatDanhSach();
                break;
            case 3:
                tinhLaiSuat();
                break;
            case 4:
                rutTien();
                break;
            case 5: {
                long cmnd;
                cout << "Nhap CMND can tim: ";
                cin >> cmnd;
                SoTietKiem* ketQua = timSoTheoCMND(cmnd);
                if (ketQua) {
                    cout << "Tim thay so tiet kiem:\n";
                    cout << setw(10) << left << "Ma so"
                         << setw(15) << left << "Loai tiet kiem"
                         << setw(35) << left << "Ho ten khach hang"
                         << setw(15) << left << "CMND"
                         << setw(12) << left << "Ngay mo so"
                         << setw(15) << right << "So tien gui" << endl;
                    cout << string(102, '-') << endl;
                    ketQua->xuatThongTin();
                } else {
                    cout << "Khong tim thay so tiet kiem voi CMND " << cmnd << ".\n";
                }
                break;
            }
            case 6: {
                string maSo;
                cout << "Nhap ma so can tim: ";
                cin >> maSo;
                SoTietKiem* ketQua = timSoTheoMaSo(maSo);
                if (ketQua) {
                    cout << "Tim thay so tiet kiem:\n";
                    cout << setw(10) << left << "Ma so"
                         << setw(15) << left << "Loai tiet kiem"
                         << setw(35) << left << "Ho ten khach hang"
                         << setw(15) << left << "CMND"
                         << setw(12) << left << "Ngay mo so"
                         << setw(15) << right << "So tien gui" << endl;
                    cout << string(102, '-') << endl;
                    ketQua->xuatThongTin();
                } else {
                    cout << "Khong tim thay so tiet kiem voi ma so " << maSo << ".\n";
                }
                break;
            }
            case 7: {
                int ngayBD, thangBD, namBD, ngayKT, thangKT, namKT;
                cout << "Nhap ngay bat dau (ngay thang nam): ";
                cin >> ngayBD >> thangBD >> namBD;
                cout << "Nhap ngay ket thuc (ngay thang nam): ";
                cin >> ngayKT >> thangKT >> namKT;
                
                lietKeSoTheoKhoangThoiGian(ngayBD, thangBD, namBD, ngayKT, thangKT, namKT);
                break;
            }
            case 8:
                sapXepTheoSoTienGiamDan();
                break;
            case 9:
                sapXepTheoNgayMoSoTangDan();
                break;
            case 0:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    } while (choice != 0);
}
