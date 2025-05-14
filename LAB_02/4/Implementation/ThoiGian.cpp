#include "ThoiGian.h"

#include <iostream>

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {};
ThoiGian::ThoiGian(int gio, int phut, int giay) : iGio(gio), iPhut(phut), iGiay(giay) {};
ThoiGian::ThoiGian(const ThoiGian& tg) : iGio(tg.iGio), iPhut(tg.iPhut), iGiay(tg.iGiay) {};

ThoiGian::~ThoiGian() {};

void ThoiGian::Nhap() {
	char holder;
	std::cout << "Nhap thoi gian (hh:mm:ss): ";
	std::cin >> iGio >> holder >> iPhut >> holder >> iGiay;
}

void ThoiGian::Xuat() const {
	std::cout << iGio << ":" << iPhut << ":" << iGiay << std::endl;
}

ThoiGian ThoiGian::TinhCongThemMotGiay() {
	ThoiGian tg(*this);
	tg.iGiay++;
	if (tg.iGiay >= 60) {
		tg.iGiay = 0;
		tg.iPhut++;
		if (tg.iPhut >= 60) {
			tg.iPhut = 0;
			tg.iGio++;
			if (tg.iGio >= 24) {
				tg.iGio = 0;
			}
		}
	}
	return tg;
}


