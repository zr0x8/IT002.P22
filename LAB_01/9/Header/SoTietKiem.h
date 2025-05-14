#ifndef SO_TIET_KIEM_H
#define SO_TIET_KIEM_H

#include <string>
#include <ctime>

using namespace std;

class SoTietKiem {
private:
    string maSo;
    string loaiTietKiem;
    string hoTenKhachHang;
    long cmnd;
    struct {
        int ngay;
        int thang;
        int nam;
    } ngayMoSo;
    double soTienGui;
    
    bool isValidDate(int ngay, int thang, int nam) const;

public:
    SoTietKiem();
    
    void nhapMaSo();
    void nhapLoaiTietKiem();
    void nhapHoTenKhachHang();
    void nhapCMND();
    void nhapNgayMoSo();
    void nhapSoTienGui();
    void nhapThongTin();
    
    void xuatThongTin() const;
    
    string getMaSo() const { return maSo; }
    string getLoaiTietKiem() const { return loaiTietKiem; }
    string getHoTenKhachHang() const { return hoTenKhachHang; }
    long getCMND() const { return cmnd; }
    int getNgayMoSo() const { return ngayMoSo.ngay; }
    int getThangMoSo() const { return ngayMoSo.thang; }
    int getNamMoSo() const { return ngayMoSo.nam; }
    double getSoTienGui() const { return soTienGui; }
    
    int tinhSoNgayGuiTien() const;
    double tinhTienLai(double laiSuat, int soNgay) const;
    bool rutTien(double soTienRut, double laiSuatTruocHan);
};

#endif
