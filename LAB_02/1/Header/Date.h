#pragma once
class Date
{
	private:
		int iNgay;
		int iThang;
		int iNam;
	public:
		Date();
		Date(int iNgay, int iThang, int iNam);
		Date(const Date& d);
		~Date();
		//getters
		void Nhap();
		void Xuat() const;
		//misc
		Date NgayThangNamTiepTheo();
		//op overload
		Date& operator=(const Date& d);
};

