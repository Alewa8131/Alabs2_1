#pragma once
#include "Point.h"

class Circle {
    int _x, _y, _r;
public:
    Circle();
    Circle(int);
    Circle(int, int);
    Circle(int, int, int);
    Circle(const Point&);
    Circle(const Point&, int);
    Circle(const Circle&);

    int get_coord_x() const;
    int get_coord_y() const;
    int get_radius() const;
};
