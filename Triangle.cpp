#include "Triangle.hpp"

/* Construct Area */
bool Triangle::Set_By_3(double sidea, double sideb, double sidec)
{
    side_a = sidea;
    side_b = sideb;
    side_c = sidec;
    angle_a = get_angle(sidea, sideb, sidec);
    angle_b = get_angle(sideb, sidea, sidec);
    angle_c = get_angle(sidec, sidea, sideb);
    if (check_valid_triangle())
    {
        set_type();
        return true;
    }
    return false;
}
bool Triangle::Set_ALL(double angle1, double length1, double length2, bool obtuse)
{
    side_a = length1;
    angle_a = angle1;
    side_b = length2;
    double sin_b = std::sin(degree_to_radian(angle_a)) * side_b / side_a;
    if (obtuse)
    {
        angle_b = 180 - radian_to_degree(std::asin(sin_b));
    }
    else
    {
        angle_b = radian_to_degree(std::asin(sin_b));
    }
    angle_c = 180 - angle_a - angle_b;
    side_c = get_length(angle_c, side_a, side_b);
    if (check_valid_triangle())
    {
        set_type();
        return true;
    }

    return false;
}
bool Triangle::Set_ALA(double angle1, double length1, double angle2)
{
    side_a = length1;
    angle_a = angle1;
    angle_b = angle2;
    side_b = std::sin(degree_to_radian(angle_b)) * side_a / std::sin(degree_to_radian(angle_a));
    angle_c = 180 - angle_a - angle_b;
    side_c = get_length(angle_c, side_a, side_b);
    if (check_valid_triangle())
    {
        set_type();
        return true;
    }
    return false;
}
/*Private Functions */
bool Triangle::check_valid_triangle()
{
    // Check triangle inequality
    if (side_a + side_b <= side_c || side_a + side_c <= side_b || side_b + side_c <= side_a)
    {
        std::cout << "Failed Length Test. Not a Valid Triangle." << std::endl;
        is_set = false;
        return false;
    }

    // Check angle validity
    if (angle_a <= 0 || angle_b <= 0 || angle_c <= 0 || angle_a >= 180 || angle_b >= 180 || angle_c >= 180)
    {
        std::cout << "Failed Angle Test. Not a Valid Triangle." << std::endl;
        is_set = false;
        return false;
    }

    return true;
}
void Triangle::set_type()
{
    if (side_a != side_b && side_a != side_c && side_b != side_c)
    {
        type_side = SIDE_TYPE::SCALENE;
    }
    else if (side_a == side_b && side_a == side_c && side_b == side_c)
    {
        type_side = SIDE_TYPE::EQUILATERAL;
    }
    else if (side_a == side_b || side_a == side_c || side_b == side_c)
    {
        type_side = SIDE_TYPE::ISOCELES;
    }

    if (is_right_triangle(side_a, side_b, side_c))
    {
        type_angle = ANGLE_TYPE::RIGHT;
    }
    else if (is_obtuse_angle(angle_a) || is_obtuse_angle(angle_b) || is_obtuse_angle(angle_c))
    {
        type_angle = ANGLE_TYPE::OBTUSE;
    }
    else
    {
        type_angle = ANGLE_TYPE::ACUTE;
    }

    is_set = true;
}
double Triangle::radian_to_degree(double radian) const
{
    return (radian * 180) / M_PI;
}
double Triangle::degree_to_radian(double degree) const
{
    return (degree * M_PI) / 180;
}
bool Triangle::is_right_triangle(double sidea, double sideb, double sidec)
{
    double tolerance = 0.00001;
    if (std::abs((sidea * sidea) + (sideb * sideb) - (sidec * sidec)) < tolerance)
    {
        return true;
    }
    else if (std::abs((sidea * sidea) + (sidec * sidec) - (sideb * sideb)) < tolerance)
    {
        return true;
    }
    else if (std::abs((sideb * sideb) + (sidec * sidec) - (sidea * sidea)) < tolerance)
    {
        return true;
    }
    return false;
}
bool Triangle::is_obtuse_angle(double degree)
{
    if (degree > 90)
    {
        return true;
    }
    return false;
}
double Triangle::get_angle(double returnside, double sideb, double sidec)
{
    double cosine_rule = ((sideb * sideb) + (sidec * sidec) - (returnside * returnside)) / (2 * sideb * sidec);
    double invert_cos = std::acos(cosine_rule);
    return radian_to_degree(invert_cos);
}
double Triangle::get_length(double angle, double sideb, double sidec)
{
    return std::sqrt(sideb * sideb + sidec * sidec - 2 * sideb * sidec * std::cos(degree_to_radian(angle)));
}
/* Public Functions */
void Triangle::print_summary() const
{
    if (is_set == false)
    {
        std::cout << "Triangle Not Set." << std::endl
                  << std::endl;
        return;
    }
    std::cout << "Types       : ";
    switch (type_angle)
    {
    case 0:
        std::cout << "Right ";
        break;
    case 1:
        std::cout << "Acute ";
        break;
    case 2:
        std::cout << "Obtuse ";
        break;
    default:
        break;
    }

    switch (type_side)
    {
    case 0:
        std::cout << "| Scalene" << std::endl;
        break;
    case 1:
        std::cout << "| Isoceles" << std::endl;
        break;
    case 2:
        std::cout << "| Equilateral" << std::endl;
        break;
    default:
        break;
    }

    std::cout.precision(2);
    std::cout.width(10);
    std::cout << "Angles      : [A]" << std::fixed << angle_a;
    std::cout.precision(2);
    std::cout.width(9);
    std::cout << "[B]" << std::fixed << angle_b;
    std::cout.precision(2);
    std::cout.width(9);
    std::cout << "[C]" << std::fixed << angle_c << std::endl;

    std::cout.precision(2);
    std::cout.width(10);
    std::cout << "Lengths     : [a]" << std::fixed << side_a;
    std::cout.precision(2);
    std::cout.width(10);
    std::cout << "[b]" << std::fixed << side_b;
    std::cout.precision(2);
    std::cout.width(10);
    std::cout << "[c]" << std::fixed << side_c << std::endl;

    std::cout << "Perimeter   : " << perimeter() << std::endl;

    std::cout << "Area        : " << area() << std::endl;
    std::cout << "Height a    : " << height('a') << std::endl;
    std::cout << "Height b    : " << height('b') << std::endl;
    std::cout << "Height c    : " << height('c') << std::endl;
    std::cout << "Base Side   : " << base() << std::endl;

    std::cout << "Inradius    : " << inradius() << std::endl;
    std::cout << "Circumradius: " << circumradius() << std::endl;

    std::cout << std::endl;
}

double Triangle::side_length(const char side_letter) const
{
    if (side_letter == 'a')
    {
        return side_a;
    }
    else if (side_letter == 'b')
    {
        return side_b;
    }
    else if (side_letter == 'c')
    {
        return side_c;
    }
    return -1.0;
}

double Triangle::angle_degree(const char angle_letter) const
{
    if (angle_letter == 'A')
    {
        return angle_a;
    }
    else if (angle_letter == 'B')
    {
        return angle_b;
    }
    else if (angle_letter == 'C')
    {
        return angle_c;
    }
    return -1.0;
}

double Triangle::angle_radian(const char angle_letter) const
{
    if (angle_letter == 'A')
    {
        return degree_to_radian(angle_a);
    }
    else if (angle_letter == 'B')
    {
        return degree_to_radian(angle_b);
    }
    else if (angle_letter == 'C')
    {
        return degree_to_radian(angle_c);
    }
    return -1.0;
}

double Triangle::area() const
{
    double s = perimeter() / 2.0;
    double area = sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    return area;
}

double Triangle::perimeter() const
{
    return side_a + side_b + side_c;
}

double Triangle::height(const char angle) const
{
    if (angle == 'a')
    {
        return (2 * area()) / side_a;
    }
    else if (angle == 'b')
    {
        return (2 * area()) / side_b;
    }
    else if (angle == 'c')
    {
        return (2 * area()) / side_c;
    }
    return -1.0;
}

char Triangle::base() const
{
    switch (type_side)
    {
    case SIDE_TYPE::EQUILATERAL:
        return 'a';
        break;
    case SIDE_TYPE::ISOCELES:
        if (side_a == side_b)
        {
            return 'c';
        }
        if (side_a == side_c)
        {
            return 'b';
        }
        if (side_c == side_b)
        {
            return 'a';
        }
        break;
    case SIDE_TYPE::SCALENE:
        return 'a';
        break;
    default:
        break;
    }
    return 0.0;
}

double Triangle::inradius() const
{
    return area() / (perimeter() / 2);
}

double Triangle::circumradius() const
{
    return ((side_a * side_b * side_c) / (4 * area()));
}
