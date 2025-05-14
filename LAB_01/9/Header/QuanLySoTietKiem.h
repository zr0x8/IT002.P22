#ifndef QUAN_LY_SO_TIET_KIEM_H
#define QUAN_LY_SO_TIET_KIEM_H

#include "SoTietKiem.h"
#include <vector>

class QuanLySoTietKiem {
private:
    std::vector<SoTietKiem> danhSachSo;
    
public:
    void themSo();
    void xuatDanhSach() const;
    void tinhLaiSuat();
    void rutTien();
    SoTietKiem* timSoTheoCMND(long cmnd);
    SoTietKiem* timSoTheoMaSo(const std::string& maSo);
    void lietKeSoTheoKhoangThoiGian(int ngayBatDau, int thangBatDau, int namBatDau, 
                                    int ngayKetThuc, int thangKetThuc, int namKetThuc);
    void sapXepTheoSoTienGiamDan();
    void sapXepTheoNgayMoSoTangDan();
    void menu();
};

#endif