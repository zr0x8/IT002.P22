#include "SoPhuc.h"

#include <iostream>
#include <string>

SoPhuc::SoPhuc() : iThuc(0), iAo(0) {};
SoPhuc::SoPhuc(float thuc, float ao) : iThuc(thuc), iAo(ao) {};
SoPhuc::SoPhuc(const SoPhuc& sp) : iThuc(sp.iThuc), iAo(sp.iAo) {};

SoPhuc::~SoPhuc() {};

void SoPhuc::Nhap() {
    std::string input;
    std::cout << "Nhap so phuc (vi du: 3+2i, 2i+3, 2i, 3): ";
    std::cin >> input;

    if (input.find('i') == std::string::npos) {
        iThuc = std::stoi(input);
        iAo = 0;
        return;
    }

    if (input.find('+') == std::string::npos && input.find('-', 1) == std::string::npos) {
        if (input == "i") {
            iThuc = 0;
            iAo = 1;
        } else if (input == "-i") {
            iThuc = 0;
            iAo = -1;
        } else {
            input.pop_back();
            iThuc = 0;
            iAo = std::stoi(input);
        }
        return;
    }

    size_t i_position = input.find('i');
    size_t plus_position = input.find('+');
    size_t minus_position = input.find('-', 1);

    size_t position = std::string::npos;
    if (plus_position != std::string::npos)
        position = plus_position;
    else if (minus_position != std::string::npos)
        position = minus_position;

    if (i_position > position && position != std::string::npos) {
        std::string real = input.substr(0, position);
        std::string unreal = input.substr(position, i_position - position);
        
        iThuc = real.empty() ? 0 : std::stoi(real);
        iAo = (unreal == "+" || unreal == "-") ? 
              (unreal == "+" ? 1 : -1) : std::stoi(unreal);
    }
    // Xử lý trường hợp "bi+a"
    else if (i_position < position) {
        std::string unreal = input.substr(0, i_position);
        std::string real = input.substr(position);
        
        iThuc = std::stoi(real);
        iAo = unreal.empty() ? 1 : (unreal == "-" ? -1 : std::stoi(unreal));
    }
}


void SoPhuc::Xuat() const {
	std::cout << iThuc << " + " << iAo << "i" << std::endl;
}

SoPhuc SoPhuc::Tong(const SoPhuc& sp) const {
    return SoPhuc(iThuc + sp.iThuc, iAo + sp.iAo);
}

SoPhuc SoPhuc::Hieu(const SoPhuc& sp) const {
    return SoPhuc(iThuc - sp.iThuc, iAo - sp.iAo);
}

SoPhuc SoPhuc::Tich(const SoPhuc& sp) const {
    return SoPhuc(iThuc * sp.iThuc - iAo * sp.iAo, iThuc * sp.iAo + iAo * sp.iThuc);
}

SoPhuc SoPhuc::Thuong(const SoPhuc& sp) const {
    int chia = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    return SoPhuc((iThuc * sp.iThuc + iAo * sp.iAo) / chia, (iAo * sp.iThuc - iThuc * sp.iAo) / chia);
}