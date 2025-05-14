#include <iostream>

#include "PhanSo.h"

int main() {
	PhanSo ps1;
	PhanSo ps2;
	std::cout << "Moi ban nhap phan so thu nhat: \n";
	ps1.Nhap();
	std::cout << "Moi ban nhap phan so thu hai: \n";
	ps2.Nhap();
	std::cout << "Gia tri cua 2 phan so sau khi rut gon la:\n";
	ps1.RutGon().Xuat();
	ps2.RutGon().Xuat();
	std::cout << "Tong cua 2 phan so la:\n";
	ps1.Tong(ps2).Xuat();
	std::cout << "Hieu cua 2 phan so la:\n";
	ps1.Hieu(ps2).Xuat();
	std::cout << "Tich cua 2 phan so la:\n";
	ps1.Tich(ps2).Xuat();
	std::cout << "Thuong cua 2 phan so la:\n";
	ps1.Thuong(ps2).Xuat();
	ps1.SoSanh(ps2);
}