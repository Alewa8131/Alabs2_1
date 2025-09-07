#pragma once
#include "Circle.h"
#include "Point3D.h"

class Sphere : public Circle {
    int _z;
public:
    Sphere();
    Sphere(int);
    Sphere(int, int, int);
    Sphere(int, int, int, int);
    Sphere(const Point&);
    Sphere(const Point&, int, int);
    Sphere(const Point3D&);
    Sphere(const Point3D&, int);
    Sphere(const Circle&);
    Sphere(const Circle&, int);
    Sphere(const Sphere&);

    int get_coord_z() const;
    double get_distance(const Sphere&);
};
