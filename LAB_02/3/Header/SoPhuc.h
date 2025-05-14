#pragma once
class SoPhuc
{
	private:
		float iThuc;
		float iAo;
	public:
		SoPhuc();
		SoPhuc(float thuc, float ao);
		SoPhuc(const SoPhuc& sp);
		~SoPhuc();

		void Nhap();
		void Xuat() const;
		SoPhuc Tong(const SoPhuc& sp) const;
		SoPhuc Hieu(const SoPhuc& sp) const;
		SoPhuc Tich(const SoPhuc& sp) const;
		SoPhuc Thuong(const SoPhuc& sp) const;
};

