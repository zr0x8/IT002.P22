#pragma once
#include "Shape.h"

#include <iostream>
#include <sstream>
#include <string>

class Trapezoid : public Shape {
private:
  double top, bottom, left, right;

public:
  Trapezoid(int h = 0, int t = 0, int b = 0, int l = 0, int r = 0);
  ~Trapezoid();

  double CalculatePerimeter() const override;
  double CalculateArea() const override;

  std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &os, const Trapezoid &t);
  friend std::istream &operator>>(std::istream &is, Trapezoid &t);
};
