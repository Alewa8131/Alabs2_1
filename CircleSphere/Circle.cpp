#include "Circle.h"

Circle::Circle() : _x(0), _y(0), _r(1) {}
Circle::Circle(int r) : _x(0), _y(0), _r(r) {}
Circle::Circle(int x, int y) : _x(x), _y(y), _r(1) {}
Circle::Circle(int x, int y, int r) : _x(x), _y(y), _r(r) {}

Circle::Circle(const Point& p) : _x(p.get_coord_x()), _y(p.get_coord_y()), _r(1) {}
Circle::Circle(const Point& p, int r) : _x(p.get_coord_x()), _y(p.get_coord_y()), _r(r) {}
Circle::Circle(const Circle& c) : _x(c.get_coord_x()), _y(c.get_coord_y()), _r(c.get_radius()) {}

int Circle::get_coord_x() const { return _x; }
int Circle::get_coord_y() const { return _y; }
int Circle::get_radius() const { return _r; }