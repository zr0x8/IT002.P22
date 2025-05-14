#include "Date.h"

#include <iostream>

Date::Date() : iNgay(1), iThang(1), iNam(1970) {};
Date::Date(int Ngay, int Thang, int Nam) : iNgay(Ngay), iThang(Thang), iNam(Nam) {};
Date::Date(const Date& other) : iNgay(other.iNgay), iThang(other.iThang), iNam(other.iNam) {};
Date::~Date() {};

void Date::Nhap() {
	char holder;
	std::cout << "Nhap ngay thang nam cua ban (dd mm yyyy): ";
	std::cin >> iNgay >> holder >> iThang >> holder >> iNam;
	std::cout << "Ngay thang nam da nhap: " << iNgay << holder << iThang << holder << iNam << '\n';
}

void Date::Xuat() const {
	std::cout << "Ngay thang nam da nhap: " << iNgay << '/' << iThang << '/' << iNam << '\n';
}

Date& Date::operator=(const Date& other) {
	if (this != &other) {
		iNgay = other.iNgay;
		iThang = other.iThang;
		iNam = other.iNam;
	}
	return *this;
}

Date Date::NgayThangNamTiepTheo() {
	int SoNgayTrongThang[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (iNam % 4 == 0 && iNam % 100 != 0 || iNam % 400 == 0) {
		SoNgayTrongThang[2] = 29;
	}
	Date mai = *this;
	if (iNgay < SoNgayTrongThang[iThang]) {
		mai.iNgay++;
	} else {
		mai.iNgay = 1;
		if (iThang < 12) {
			mai.iThang++;
		} else {
			mai.iThang = 1;
			mai.iNam++;
		}
	}
	return mai;
}
