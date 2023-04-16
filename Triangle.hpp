#pragma once

#include <iostream>
#include <cmath>

enum ANGLE_TYPE
{
    RIGHT,
    ACUTE,
    OBTUSE,
};

enum SIDE_TYPE
{
    SCALENE,
    ISOCELES,
    EQUILATERAL,
};

class Triangle
{
private:
    bool is_set = false;

    ANGLE_TYPE type_angle = ANGLE_TYPE::ACUTE;
    SIDE_TYPE type_side = SIDE_TYPE::EQUILATERAL;

    double side_a = 0;
    double side_b = 0;
    double side_c = 0;

    double angle_a = 0;
    double angle_b = 0;
    double angle_c = 0;

    double height_a = 0;
    double height_b = 0;
    double height_c = 0;

private:
    double radian_to_degree(double radian) const;
    double degree_to_radian(double degree) const;
    bool is_right_triangle(double sidea, double sideb, double sidec);
    bool is_obtuse_angle(double degree);
    double get_angle(double sidea, double sideb, double sidec);
    double get_length(double angle, double sideb, double sidec);
    bool check_valid_triangle();
    void set_type();

public:
    Triangle() = default;
    ~Triangle() = default;
    bool Set_By_3(double sidea, double sideb, double sidec);
    bool Set_ALL(double angle1, double length1, double length2, bool obtuse);
    bool Set_ALA(double angle1, double length1, double angle2);
    void print_summary() const;
    double side_length(const char side_letter) const;
    double angle_radian(const char angle_letter) const;
    double angle_degree(const char angle_letter) const;
    double area() const;
    double perimeter() const;
    double height(const char angle) const;
    char base() const;
    double inradius() const;
    double circumradius() const;
};
