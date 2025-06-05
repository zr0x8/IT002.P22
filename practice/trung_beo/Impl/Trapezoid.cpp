#include "Trapezoid.h"

#include <iostream>

Trapezoid::Trapezoid(int h, int t, int b, int l, int r)
    : Shape(h), top(t), bottom(b), left(l), right(r) {};

Trapezoid::~Trapezoid() = default;

double Trapezoid::CalculatePerimeter() const {
  return top + bottom + left + right;
}

double Trapezoid::CalculateArea() const { return (top + bottom) / 2 * height; }

std::string Trapezoid::ToString() const { std::ostringstream oss;
  oss << "[Hinh thang]\nCanh day tren: " << top
      << "\nCanh day duoi: " << bottom << "\nCanh trai: " << left
      << "\nCanh phai: " << right << "\nChieu cao: " << height;
  return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Trapezoid &t) {
  os << "[Hinh thang]\nCanh day tren: " << t.top
     << "\nCanh day duoi: " << t.bottom << "\nCanh trai: " << t.left
     << "\nCanh phai: " << t.right << "\nChieu cao: " << t.height;
  return os;
}

std::istream& operator>>(std::istream& is, Trapezoid& t) { 
  char holder;
  is >> t.height >> holder >> t.top >> holder >> t.bottom >> holder >> t.left >>
      holder >> t.right;
  return is;
}