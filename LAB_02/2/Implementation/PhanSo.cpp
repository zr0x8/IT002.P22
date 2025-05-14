#include "PhanSo.h"

#include <iostream>

int GCD(const int& a, const int& b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

PhanSo::PhanSo() : iTu(0), iMau(1) {};
PhanSo::PhanSo(int tu, int mau) : iTu(tu), iMau(mau) {
	if (iMau == 0) {
		iMau = 1;
	}
};
PhanSo::PhanSo(const PhanSo& ps) : iTu(ps.iTu), iMau(ps.iMau) {};

PhanSo::~PhanSo() {};

void PhanSo::Nhap() {
	char holder;
	do {
		std::cin >> iTu >> holder >> iMau;
		if (iMau == 0) {
			std::cout << "Phan so khong hop le, vui long nhap lai: \n";
		}
	} while (iMau == 0);
}

void PhanSo::Xuat() const {
	std::cout << iTu << "/" << iMau << '\n';
}

PhanSo PhanSo::RutGon() const {
	int gcd = GCD(abs(iTu), abs(iMau));
	if (gcd == 0) return PhanSo(0, 1);
	if (gcd == 1) return *this;
	return PhanSo(iTu / gcd, iMau / gcd);
}

PhanSo PhanSo::Tong(const PhanSo& ps) const {
	return PhanSo(iTu * ps.iMau + ps.iTu * iMau, iMau * ps.iMau).RutGon();
}

PhanSo PhanSo::Hieu(const PhanSo& ps) const {
	PhanSo ket_qua;

	return PhanSo(iTu * ps.iMau - ps.iTu * iMau, iMau * ps.iMau).RutGon();
}

PhanSo PhanSo::Tich(const PhanSo& ps) const {
	return PhanSo(iTu * ps.iTu, iMau * ps.iMau).RutGon();
}

PhanSo PhanSo::Thuong(const PhanSo& ps) const {
	return PhanSo(iTu * ps.iMau, iMau * ps.iTu).RutGon();
}

void PhanSo::SoSanh(const PhanSo& ps) const {
	double ps1 = this->iTu / this->iMau;
	double ps2 = ps.iTu / ps.iMau;
	if (ps1 > ps2) {
		std::cout << "Phan so 1 > phan so 2\n";
	}
	else if (ps1 < ps2) {
		std::cout << "Phan so 1 < phan so 2\n";
	}
	else {
		std::cout << "Phan so 1 = phan so 2\n";
	}
}



