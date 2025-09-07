#include <stdio.h>
#include <iostream>
#include "Point.h"

int main() {
    Point p(4);
    printf("%d %d", p.get_coord_x(), p.get_coord_y());
}