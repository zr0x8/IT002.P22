#include "Parallelogram.h"

Parallelogram::Parallelogram(int h, int b, int s)
    : Shape(h), bottom(b), side(s) {};

Parallelogram::~Parallelogram() = default;

double Parallelogram::CalculatePerimeter() const {
  return (this->side + this->bottom) * 2;
}

double Parallelogram::CalculateArea() const {
  return this->bottom * this->height;
}

std::string Parallelogram::ToString() const { 
  std::ostringstream oss;
  oss << "[Hinh binh hanh]\nCanh day: " << bottom << "\nCanh ben: " << side
      << "\nChieu cao: " << height;
  return oss.str();
}

std::ostream &operator<<(std::ostream &os, const Parallelogram &p) {
  os << "[Hinh binh hanh]\nCanh day: " << p.bottom << "\nCanh ben: " << p.side
     << "\nChieu cao: " << p.height;
  return os;
}

std::istream &operator>>(std::istream &is, Parallelogram &p) {
  char holder;
  is >> p.height >> holder >> p.bottom >> holder >> p.side;
  return is;
}