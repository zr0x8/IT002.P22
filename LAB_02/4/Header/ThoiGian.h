#pragma once
class ThoiGian
{
	private:
		int iGio, iPhut, iGiay;
	public:
		ThoiGian();
		ThoiGian(int gio, int phut, int giay);
		ThoiGian(const ThoiGian& tg);
		~ThoiGian();

		void Nhap();
		void Xuat() const;

		ThoiGian TinhCongThemMotGiay();
};

