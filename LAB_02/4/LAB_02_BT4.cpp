#include "ThoiGian.h"

#include <iostream>
int main() {
	ThoiGian tg;
	tg.Nhap();
	std::cout << "Mot giay sau thoi gian ban vua nhap se la: ";
	tg.TinhCongThemMotGiay().Xuat();
	return 0;
}