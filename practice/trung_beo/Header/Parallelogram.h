#pragma once
#include "Shape.h"

#include <iostream>
#include <sstream>
#include <string>

class Parallelogram : public Shape {
private:
  double bottom, side;

public:
  Parallelogram(int h = 0, int b = 0, int s = 0);
  ~Parallelogram();

  double CalculatePerimeter() const override;
  double CalculateArea() const override;

  std::string ToString() const override;

  friend std::ostream &operator<<(std::ostream &os, const Parallelogram &p);
  friend std::istream &operator>>(std::istream &is, Parallelogram &p);
};
