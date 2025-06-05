#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
protected:
  double height;

public:
  Shape(int h = 0);
  ~Shape();

  virtual double CalculatePerimeter() const = 0;
  virtual double CalculateArea() const = 0;

  virtual std::string ToString() const = 0; //i wasted 1hr for this approach lmao
};

#endif