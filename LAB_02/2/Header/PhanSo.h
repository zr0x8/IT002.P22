#pragma once
class PhanSo
{
	private:
		int iTu;
		int iMau;
	public:
		PhanSo();
		PhanSo(int iTu, int iMau);
		PhanSo(const PhanSo& ps);
		~PhanSo();
		//set getters
		void Nhap();
		void Xuat() const;
		//misc
		PhanSo RutGon() const;
		PhanSo Tong(const PhanSo& ps) const;
		PhanSo Hieu(const PhanSo& ps) const;
		PhanSo Tich(const PhanSo& ps) const;
		PhanSo Thuong(const PhanSo& ps) const;
		void SoSanh(const PhanSo& ps) const;

};

