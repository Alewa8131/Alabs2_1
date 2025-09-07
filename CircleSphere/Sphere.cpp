#include "Sphere.h"

Sphere::Sphere() : Circle(), _z(0) {}
Sphere::Sphere(int r) : Circle(r), _z(0) {}
Sphere::Sphere(int x, int y, int z) : Circle(x, y), _z(z) {}
Sphere::Sphere(int x, int y, int z, int r) : Circle(x, y, r), _z(z) {}

Sphere::Sphere(const Point3D& p) : Circle(p), _z(p.get_coord_z()) {} // TODO: Проверить сходятся ли коорды у Point и Point3D ?
Sphere::Sphere(const Point3D& p, int r) : Circle(p, r), _z(p.get_coord_z()) {}

Sphere::Sphere(const Circle& c) : Circle(c), _z(0) {}
Sphere::Sphere(const Circle& c, int z) : Circle(c), _z(z) {}

Sphere::Sphere(const Sphere& c) : Circle(c), _z(c.get_coord_z()) {} // TODO: Проверить сходятся ли коорды у Circle и Sphere ?


int Sphere::get_coord_z() const { return _z; }
