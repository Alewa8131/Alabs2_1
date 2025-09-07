#pragma once

class Point {
    int _x, _y;
public:
    Point();
    Point(int);
    Point(int, int);
    Point(const Point&);
    int get_coord_x() const;
    int get_coord_y() const;
};
