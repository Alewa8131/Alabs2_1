#pragma once
#include "Point.h"

class Point3D : public Point {
    int _z;
public:
    Point3D();
    Point3D(int);
    Point3D(int, int);
    Point3D(int, int, int);
    Point3D(const Point3D&);
    Point3D(const Point&);
    int get_coord_z() const;
};