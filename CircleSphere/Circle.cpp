#include "Circle.h"

Circle::Circle() : Point(), _r(1) {}
Circle::Circle(int r) : Point(), _r(r) {}
Circle::Circle(int x, int y) : Point(x, y), _r(1) {}
Circle::Circle(int x, int y, int r) : Point(x, y), _r(r) {}

Circle::Circle(const Point& p) : Point(p), _r(1) {}
Circle::Circle(const Point& p, int r) : Point(p), _r(r) {}
Circle::Circle(const Circle& c) : Point(c), _r(c.get_radius()) {}


int Circle::get_radius() const { return _r; }