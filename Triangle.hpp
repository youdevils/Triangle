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
    ISOSCELES,
    EQUILATERAL,
};

class Triangle
{
private:
    bool is_set = false;
    double equivalence_tolerance = 0.0001;

    ANGLE_TYPE angle_type = ANGLE_TYPE::ACUTE;
    SIDE_TYPE side_type = SIDE_TYPE::EQUILATERAL;

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
    double Radian_To_Degree(double radian) const;
    double Degree_To_Radian(double degree) const;
    double Angle_By_Cosine(double returnside, double sideb, double sidec);
    double Length_By_Cosine(double angle, double sideb, double sidec);
    bool Check_Valid_Triangle();
    void Set_Triangle_Classification();

public:
    Triangle() = default;
    ~Triangle() = default;
    bool Set_By_Length(double sidea, double sideb, double sidec);
    bool Set_ALL(double angleA, double lengtha, double lengthb, bool obtuse);
    bool Set_LLA(double angleA, double lengthb, double lengthc);
    bool Set_ALA(double angleA, double lengtha, double angleb);
    void Print_Summary() const;
    double Get_Length(const char side_letter) const;
    double Get_Radian_Angle(const char angle_letter) const;
    double Get_Degree_Angle(const char angle_letter) const;
    double Get_Area() const;
    double Get_Perimeter() const;
    double Get_Height(const char angle) const;
    char Get_Base() const;
    double Get_Inradius() const;
    double Get_Circumradius() const;
};
