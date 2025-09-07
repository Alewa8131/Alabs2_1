#pragma once
#include "Point.h"

class Circle : public Point {
    int _r;
public:
    Circle();
    Circle(int);
    Circle(int, int);
    Circle(int, int, int);
    Circle(const Point&);
    Circle(const Point&, int);
    Circle(const Circle&);

    int get_radius() const;
    double get_distance(const Circle&);
};
