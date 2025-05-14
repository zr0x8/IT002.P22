#include "SoTietKiem.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>

using namespace std;

SoTietKiem::SoTietKiem() : cmnd(0), soTienGui(0) {
    ngayMoSo.ngay = 0;
    ngayMoSo.thang = 0;
    ngayMoSo.nam = 0;
}

void SoTietKiem::nhapMaSo() {
    while (true) {
        cout << "Nhap ma so (toi da 5 ky tu, khong co khoang trang hoac ky tu dac biet): ";
        cin >> maSo;
        
        bool valid = true;
        
        if (maSo.length() > 5) {
            cout << "Loi: Ma so khong duoc vuot qua 5 ky tu.\n";
            valid = false;
        }
        
        for (char c : maSo) {
            if (!isalnum(c)) {
                cout << "Loi: Ma so chi duoc chua chu cai va so.\n";
                valid = false;
                break;
            }
        }
        
        if (valid) break;
    }
}

void SoTietKiem::nhapLoaiTietKiem() {
    cin.ignore();
    while (true) {
        cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
        getline(cin, loaiTietKiem);
        
        if (loaiTietKiem.length() <= 10) break;
        
        cout << "Loi: Loai tiet kiem khong duoc vuot qua 10 ky tu.\n";
    }
}

void SoTietKiem::nhapHoTenKhachHang() {
    cin.ignore(cin.rdbuf()->in_avail());
    while (true) {
        cout << "Nhap ho ten khach hang (toi da 30 ky tu, khong chua so hoac ky tu dac biet): ";
        getline(cin, hoTenKhachHang);
        
        bool valid = true;
        
        if (hoTenKhachHang.length() > 30) {
            cout << "Loi: Ho ten khong duoc vuot qua 30 ky tu.\n";
            valid = false;
        }
        
        for (char c : hoTenKhachHang) {
            if (!isalpha(c) && c != ' ') {
                cout << "Loi: Ho ten chi duoc chua chu cai va khoang trang.\n";
                valid = false;
                break;
            }
        }
        
        if (valid) break;
    }
}

void SoTietKiem::nhapCMND() {
    while (true) {
        cout << "Nhap CMND (9 hoac 12 chu so): ";
        cin >> cmnd;
        
        long temp = cmnd;
        int digitCount = 0;
        
        if (temp == 0) digitCount = 1;
        else {
            while (temp > 0) {
                temp /= 10;
                digitCount++;
            }
        }
        
        if (digitCount == 9 || digitCount == 12) break;
        
        cout << "Loi: CMND phai co 9 hoac 12 chu so.\n";
    }
}

bool SoTietKiem::isValidDate(int ngay, int thang, int nam) const {
    if (nam < 0 || thang < 1 || thang > 12 || ngay < 1) 
        return false;
        
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (thang == 2) {
        bool isLeap = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
        if (isLeap) daysInMonth[2] = 29;
    }
    
    return ngay <= daysInMonth[thang];
}

void SoTietKiem::nhapNgayMoSo() {
    while (true) {
        cout << "Nhap ngay mo so (ngay thang nam): ";
        cin >> ngayMoSo.ngay >> ngayMoSo.thang >> ngayMoSo.nam;
        
        if (isValidDate(ngayMoSo.ngay, ngayMoSo.thang, ngayMoSo.nam)) break;
        
        cout << "Loi: Ngay khong hop le.\n";
    }
}

void SoTietKiem::nhapSoTienGui() {
    while (true) {
        cout << "Nhap so tien gui: ";
        cin >> soTienGui;
        
        if (soTienGui > 0) break;
        
        cout << "Loi: So tien gui phai la so duong.\n";
    }
}

void SoTietKiem::nhapThongTin() {
    nhapMaSo();
    nhapLoaiTietKiem();
    nhapHoTenKhachHang();
    nhapCMND();
    nhapNgayMoSo();
    nhapSoTienGui();
}

void SoTietKiem::xuatThongTin() const {
    cout << setw(10) << left << maSo
         << setw(15) << left << loaiTietKiem
         << setw(35) << left << hoTenKhachHang
         << setw(15) << left << cmnd
         << setw(2) << right << ngayMoSo.ngay << "/"
         << setw(2) << setfill('0') << right << ngayMoSo.thang << "/"
         << setw(4) << setfill('0') << right << ngayMoSo.nam << setfill(' ')
         << setw(15) << right << fixed << setprecision(2) << soTienGui << endl;
}

int SoTietKiem::tinhSoNgayGuiTien() const {
    time_t now = time(nullptr);
    tm currentTime;
	localtime_s(&currentTime, &now);
    
    tm openDate = {};
    openDate.tm_year = ngayMoSo.nam - 1900;
    openDate.tm_mon = ngayMoSo.thang - 1;
    openDate.tm_mday = ngayMoSo.ngay;
    
    double seconds = difftime(now, mktime(&openDate));
    
    return static_cast<int>(seconds / (60 * 60 * 24));
}

double SoTietKiem::tinhTienLai(double laiSuat, int soNgay) const {
    double laiSuatApDung = laiSuat;

    if (loaiTietKiem == "ngan han") {
        if (soNgay > 180) {
            soNgay = 180;
        }
    }

    return soTienGui * (laiSuatApDung / 100.0) * (soNgay / 365.0);
}

bool SoTietKiem::rutTien(double soTienRut, double laiSuatTruocHan) {
    if (soTienRut <= 0) {
        cout << "Loi: So tien rut phai lon hon 0.\n";
        return false;
    }
    
    if (soTienRut > soTienGui) {
        cout << "Loi: So tien rut khong duoc vuot qua so tien gui.\n";
        return false;
    }
    
    int soNgayGui = tinhSoNgayGuiTien();

    bool truocHan = false;
    if ((loaiTietKiem == "ngan han" && soNgayGui < 30) || 
        (loaiTietKiem == "dai han" && soNgayGui < 180)) {
        cout << "Canh bao: Rut tien truoc han! Lai suat se giam xuong " 
             << laiSuatTruocHan << "%/nam.\n";
        truocHan = true;
    }
    
    soTienGui -= soTienRut;
    
    cout << "Rut tien thanh cong. So tien con lai trong so: " << soTienGui << endl;
    
    return true;
}
