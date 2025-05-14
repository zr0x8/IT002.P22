#include "Date.h"

#include <iostream>

int main() {
	Date hehe; //chua thong tin nguoi dung nhap
	hehe.Nhap();
	std::cout << "Ngay tiep theo la: ";
	hehe.NgayThangNamTiepTheo().Xuat();
	std::cout << "Bye bye\n";
	return 0;
}