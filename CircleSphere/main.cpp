#include <stdio.h>
#include <iostream>
#include <windows.h>

#include "Point3D.h"
#include "Sphere.h"


void set_color(int text_color, int bg_color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bg_color << 4) | text_color);
}

#define RUN_TEST(test) TestSystem::start_test(test, #test)

namespace TestSystem {
    int count_success = 0, count_failed = 0;

    void start_test(bool(*test)(), const char* name_of_test) {
        set_color(2, 0);
        std::cout << "[ RUN       ] ";
        set_color(7, 0);
        std::cout << name_of_test << std::endl;

        bool status = test();

        if (status == true) {
            set_color(2, 0);
            std::cout << "[        OK ]" << std::endl;
            count_success++;
        }
        else {
            set_color(4, 0);
            std::cout << "[  FAILED   ]" << std::endl;
            count_failed++;
        }
        set_color(7, 0);
    }

    template <class T>
    bool check(const T& expected, const T& actual) {
        if (expected == actual) {
            return true;
        }
        else {
            std::cerr << "Expected result is " << expected << ", but actual is " << actual << "." << std::endl;
            return false;
        }
    }

    void print_init_info() {
        set_color(2, 0);
        std::cout << "[==========] " << std::endl;
        set_color(7, 0);
    }

    void print_final_info() {
        set_color(2, 0);
        std::cout << "[==========] ";
        set_color(7, 0);
        std::cout << count_success + count_failed << " test" << (count_success + count_failed > 1 ? "s" : "") << " ran." << std::endl;
        set_color(2, 0);
        std::cout << "[  PASSED  ] ";
        set_color(7, 0);
        std::cout << count_success << " test" << (count_success > 1 ? "s" : "") << std::endl;
        if (count_failed > 0) {
            set_color(4, 0);
            std::cout << "[  FAILED  ] ";
            set_color(7, 0);
            std::cout << count_failed << " test" << (count_failed > 1 ? "s." : ".") << std::endl;
        }
    }
};

bool test_point_default_constructor() {
    Point p;
    return TestSystem::check(p.get_coord_x(), 0) &&
        TestSystem::check(p.get_coord_y(), 0);
}
bool test_point_one_param_constructor() {
    Point p(10);
    return TestSystem::check(p.get_coord_x(), 10) &&
        TestSystem::check(p.get_coord_y(), 0);
}
bool test_point_two_param_constructor() {
    Point p(5, 8);
    return TestSystem::check(p.get_coord_x(), 5) &&
        TestSystem::check(p.get_coord_y(), 8);
}
bool test_point_copy_constructor() {
    Point p1(5, 8);
    Point p2(p1);
    return TestSystem::check(p1.get_coord_x(), 5) &&
        TestSystem::check(p1.get_coord_y(), 8) &&
        TestSystem::check(p2.get_coord_x(), 5) &&
        TestSystem::check(p2.get_coord_y(), 8);
}

bool test_point3d_default_constructor() {
    Point3D p;
    return TestSystem::check(p.get_coord_x(), 0) &&
        TestSystem::check(p.get_coord_y(), 0) &&
        TestSystem::check(p.get_coord_z(), 0);
}
bool test_point3d_one_param_constructor() {
    Point3D p(10);
    return TestSystem::check(p.get_coord_x(), 10) &&
        TestSystem::check(p.get_coord_y(), 0) &&
        TestSystem::check(p.get_coord_z(), 0);
}
bool test_point3d_two_param_constructor() {
    Point3D p(5, 8);
    return TestSystem::check(p.get_coord_x(), 5) &&
        TestSystem::check(p.get_coord_y(), 8) &&
        TestSystem::check(p.get_coord_z(), 0);
}
bool test_point3d_three_param_constructor() {
    Point3D p(2, 4, 6);
    return TestSystem::check(p.get_coord_x(), 2) &&
        TestSystem::check(p.get_coord_y(), 4) &&
        TestSystem::check(p.get_coord_z(), 6);
}
bool test_point3d_copy_constructor() {
    Point3D p1(2, 4, 6);
    Point3D p2(p1);
    return TestSystem::check(p1.get_coord_x(), 2) &&
        TestSystem::check(p1.get_coord_y(), 4) &&
        TestSystem::check(p1.get_coord_z(), 6) &&
        TestSystem::check(p2.get_coord_x(), 2) &&
        TestSystem::check(p2.get_coord_y(), 4) &&
        TestSystem::check(p2.get_coord_z(), 6);
}
bool test_point3d_from_point_constructor() {
    Point p_base(7, 9);
    Point3D p3d(p_base);
    return TestSystem::check(p3d.get_coord_x(), 7) &&
        TestSystem::check(p3d.get_coord_y(), 9) &&
        TestSystem::check(p3d.get_coord_z(), 0);
}
bool test_point3d_from_point_and_param_constructor() {
    Point p_base(8, 2);
    Point3D p3d(p_base, 25);
    return TestSystem::check(p3d.get_coord_x(), 8) &&
        TestSystem::check(p3d.get_coord_y(), 2) &&
        TestSystem::check(p3d.get_coord_z(), 25);
}


bool test_circle_default_constructor() {
    Circle c;
    return TestSystem::check(c.get_coord_x(), 0) &&
        TestSystem::check(c.get_coord_y(), 0) &&
        TestSystem::check(c.get_radius(), 1);
}
bool test_circle_one_param_constructor() {
    Circle c(5);
    return TestSystem::check(c.get_coord_x(), 0) &&
        TestSystem::check(c.get_coord_y(), 0) &&
        TestSystem::check(c.get_radius(), 5);
}
bool test_circle_two_param_constructor() {
    Circle c(10, 20);
    return TestSystem::check(c.get_coord_x(), 10) &&
        TestSystem::check(c.get_coord_y(), 20) &&
        TestSystem::check(c.get_radius(), 1);
}
bool test_circle_three_param_constructor() {
    Circle c(10, 20, 5);
    return TestSystem::check(c.get_coord_x(), 10) &&
        TestSystem::check(c.get_coord_y(), 20) &&
        TestSystem::check(c.get_radius(), 5);
}
bool test_circle_from_point_constructor() {
    Point p(15, 25);
    Circle c(p);
    return TestSystem::check(c.get_coord_x(), 15) &&
        TestSystem::check(c.get_coord_y(), 25) &&
        TestSystem::check(c.get_radius(), 1);
}
bool test_circle_from_point_and_radius_constructor() {
    Point p(15, 25);
    Circle c(p, 7);
    return TestSystem::check(c.get_coord_x(), 15) &&
        TestSystem::check(c.get_coord_y(), 25) &&
        TestSystem::check(c.get_radius(), 7);
}
bool test_circle_copy_constructor() {
    Circle c1(10, 20, 5);
    Circle c2(c1);
    return TestSystem::check(c1.get_coord_x(), 10) &&
        TestSystem::check(c1.get_coord_y(), 20) &&
        TestSystem::check(c1.get_radius(), 5) &&
        TestSystem::check(c2.get_coord_x(), 10) &&
        TestSystem::check(c2.get_coord_y(), 20) &&
        TestSystem::check(c2.get_radius(), 5);
}

bool test_sphere_default_constructor() {
    Sphere s;
    return TestSystem::check(s.get_coord_x(), 0) &&
        TestSystem::check(s.get_coord_y(), 0) &&
        TestSystem::check(s.get_coord_z(), 0) &&
        TestSystem::check(s.get_radius(), 1);
}
bool test_sphere_one_param_constructor() {
    Sphere s(5);
    return TestSystem::check(s.get_coord_x(), 0) &&
        TestSystem::check(s.get_coord_y(), 0) &&
        TestSystem::check(s.get_coord_z(), 0) &&
        TestSystem::check(s.get_radius(), 5);
}
bool test_sphere_three_param_constructor() {
    Sphere s(10, 20, 30);
    return TestSystem::check(s.get_coord_x(), 10) &&
        TestSystem::check(s.get_coord_y(), 20) &&
        TestSystem::check(s.get_coord_z(), 30) &&
        TestSystem::check(s.get_radius(), 1);
}
bool test_sphere_four_param_constructor() {
    Sphere s(10, 20, 30, 5);
    return TestSystem::check(s.get_coord_x(), 10) &&
        TestSystem::check(s.get_coord_y(), 20) &&
        TestSystem::check(s.get_coord_z(), 30) &&
        TestSystem::check(s.get_radius(), 5);
}
bool test_sphere_from_point_constructor() {
    Point p(15, 25);
    Sphere s(p);
    return TestSystem::check(s.get_coord_x(), 15) &&
        TestSystem::check(s.get_coord_y(), 25) &&
        TestSystem::check(s.get_coord_z(), 0) &&
        TestSystem::check(s.get_radius(), 1);
}
bool test_sphere_from_point_and_z_coord_and_radius_constructor() {
    Point p(15, 25);
    Sphere s(p, 35, 7);
    return TestSystem::check(s.get_coord_x(), 15) &&
        TestSystem::check(s.get_coord_y(), 25) &&
        TestSystem::check(s.get_coord_z(), 35) &&
        TestSystem::check(s.get_radius(), 7);
}
bool test_sphere_from_point3d_constructor() {
    Point3D p(15, 25, 35);
    Sphere s(p);
    return TestSystem::check(s.get_coord_x(), 15) &&
        TestSystem::check(s.get_coord_y(), 25) &&
        TestSystem::check(s.get_coord_z(), 35) &&
        TestSystem::check(s.get_radius(), 1);
}
bool test_sphere_from_point3d_and_radius_constructor() {
    Point3D p(15, 25, 35);
    Sphere s(p, 7);
    return TestSystem::check(s.get_coord_x(), 15) &&
        TestSystem::check(s.get_coord_y(), 25) &&
        TestSystem::check(s.get_coord_z(), 35) &&
        TestSystem::check(s.get_radius(), 7);
}
bool test_sphere_from_circle_constructor() {
    Circle c(10, 20, 5);
    Sphere s(c);
    return TestSystem::check(s.get_coord_x(), 10) &&
        TestSystem::check(s.get_coord_y(), 20) &&
        TestSystem::check(s.get_coord_z(), 0) &&
        TestSystem::check(s.get_radius(), 5);
}
bool test_sphere_from_circle_and_z_constructor() {
    Circle c(10, 20, 5);
    Sphere s(c, 30);
    return TestSystem::check(s.get_coord_x(), 10) &&
        TestSystem::check(s.get_coord_y(), 20) &&
        TestSystem::check(s.get_coord_z(), 30) &&
        TestSystem::check(s.get_radius(), 5);
}
bool test_sphere_copy_constructor() {
    Sphere s1(10, 20, 30, 5);
    Sphere s2(s1);
    return TestSystem::check(s1.get_coord_x(), 10) &&
        TestSystem::check(s1.get_coord_y(), 20) &&
        TestSystem::check(s1.get_coord_z(), 30) &&
        TestSystem::check(s1.get_radius(), 5) &&
        TestSystem::check(s2.get_coord_x(), 10) &&
        TestSystem::check(s2.get_coord_y(), 20) &&
        TestSystem::check(s2.get_coord_z(), 30) &&
        TestSystem::check(s2.get_radius(), 5);
}




template <class T>
int check_position(T& obj1, T& obj2) {
    double distance = obj1.get_distance(obj2);
    double sum_radius = obj1.get_radius() + obj2.get_radius();
    double diff_radius = std::abs(obj1.get_radius() - obj2.get_radius());

    if (distance == 0 && obj1.get_radius() == obj2.get_radius()) {
        return 0; // "The objects match."
    }
    else if (distance < diff_radius) {
        return 1; // "One object is nested inside another and does not touch." << std::endl;
    }
    else if (distance == diff_radius) {
        return 2; // "The objects touch in an internal way." << std::endl;
    }
    else if (distance < sum_radius) {
        return 3; // "The objects intersect." << std::endl;
    }
    else if (distance == sum_radius) {
        return 4; // "The objects touch in an external way." << std::endl;
    }
    else {
        return 5; // "The objects are separate." << std::endl;
    }
}




bool test_circles_identical() {
    Circle c1(0, 0, 5);
    Circle c2(0, 0, 5);
    return TestSystem::check(check_position(c1, c2), 0);
}
bool test_circles_contained() {
    Circle c1(0, 0, 10);
    Circle c2(2, 0, 5);
    return TestSystem::check(check_position(c1, c2), 1);
}
bool test_circles_internal_touch() {
    Circle c1(0, 0, 10);
    Circle c2(5, 0, 5);
    return TestSystem::check(check_position(c1, c2), 2);
}
bool test_circles_intersect() {
    Circle c1(0, 0, 5);
    Circle c2(7, 0, 5);
    return TestSystem::check(check_position(c1, c2), 3);
}
bool test_circles_external_touch() {
    Circle c1(0, 0, 5);
    Circle c2(10, 0, 5);
    return TestSystem::check(check_position(c1, c2), 4);
}
bool test_circles_separate() {
    Circle c1(0, 0, 5);
    Circle c2(12, 0, 5);
    return TestSystem::check(check_position(c1, c2), 5);
}


bool test_spheres_identical() {
    Sphere s1(0, 0, 0, 5);
    Sphere s2(0, 0, 0, 5);
    return TestSystem::check(check_position(s1, s2), 0);
}
bool test_spheres_contained() {
    Sphere s1(0, 0, 0, 10);
    Sphere s2(2, 0, 0, 5);
    return TestSystem::check(check_position(s1, s2), 1);
}
bool test_spheres_internal_touch() {
    Sphere s1(0, 0, 0, 10);
    Sphere s2(5, 0, 0, 5);
    return TestSystem::check(check_position(s1, s2), 2);
}
bool test_spheres_intersect() {
    Sphere s1(0, 0, 0, 5);
    Sphere s2(7, 0, 0, 5);
    return TestSystem::check(check_position(s1, s2), 3);
}
bool test_spheres_external_touch() {
    Sphere s1(0, 0, 0, 5);
    Sphere s2(10, 0, 0, 5);
    return TestSystem::check(check_position(s1, s2), 4);
}
bool test_spheres_separate() {
    Sphere s1(0, 0, 0, 5);
    Sphere s2(12, 0, 0, 5);
    return TestSystem::check(check_position(s1, s2), 5);
}



int main() {
    TestSystem::print_init_info();

    RUN_TEST(test_point_default_constructor);
    RUN_TEST(test_point_one_param_constructor);
    RUN_TEST(test_point_two_param_constructor);
    RUN_TEST(test_point_copy_constructor);

    RUN_TEST(test_point3d_default_constructor);
    RUN_TEST(test_point3d_one_param_constructor);
    RUN_TEST(test_point3d_two_param_constructor);
    RUN_TEST(test_point3d_three_param_constructor);
    RUN_TEST(test_point3d_copy_constructor);
    RUN_TEST(test_point3d_from_point_constructor);
    RUN_TEST(test_point3d_from_point_and_param_constructor);


    RUN_TEST(test_circle_default_constructor);
    RUN_TEST(test_circle_one_param_constructor);
    RUN_TEST(test_circle_two_param_constructor);
    RUN_TEST(test_circle_three_param_constructor);
    RUN_TEST(test_circle_from_point_constructor);
    RUN_TEST(test_circle_from_point_and_radius_constructor);
    RUN_TEST(test_circle_copy_constructor);

    RUN_TEST(test_sphere_default_constructor);
    RUN_TEST(test_sphere_one_param_constructor);
    RUN_TEST(test_sphere_three_param_constructor);
    RUN_TEST(test_sphere_four_param_constructor);
    RUN_TEST(test_sphere_from_point_constructor);
    RUN_TEST(test_sphere_from_point_and_z_coord_and_radius_constructor);
    RUN_TEST(test_sphere_from_point3d_constructor);
    RUN_TEST(test_sphere_from_point3d_and_radius_constructor);
    RUN_TEST(test_sphere_from_circle_constructor);
    RUN_TEST(test_sphere_from_circle_and_z_constructor);
    RUN_TEST(test_sphere_copy_constructor);


    RUN_TEST(test_circles_identical);
    RUN_TEST(test_circles_contained);
    RUN_TEST(test_circles_internal_touch);
    RUN_TEST(test_circles_intersect);
    RUN_TEST(test_circles_external_touch);
    RUN_TEST(test_circles_separate);

    RUN_TEST(test_spheres_identical);
    RUN_TEST(test_spheres_contained);
    RUN_TEST(test_spheres_internal_touch);
    RUN_TEST(test_spheres_intersect);
    RUN_TEST(test_spheres_external_touch);
    RUN_TEST(test_spheres_separate);

    TestSystem::print_final_info();
    return 0;
}