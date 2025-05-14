#include "SoPhuc.h"
#include <iostream>

int main() {
	SoPhuc sp1, sp2;
	std::cout << "So phuc thu nhat: \n";
	sp1.Nhap();
	std::cout << "So phuc thu hai: \n";
	sp2.Nhap();
	std::cout << "Tong hai so phuc: \n";
	sp1.Tong(sp2).Xuat();
	std::cout << "Hieu hai so phuc: \n";
	sp1.Hieu(sp2).Xuat();
	std::cout << "Tich hai so phuc: \n";
	sp1.Tich(sp2).Xuat();
	std::cout << "Thuong hai so phuc: \n";
	sp1.Thuong(sp2).Xuat();
}