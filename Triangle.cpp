#include "Triangle.hpp"

/* Construct Area */
bool Triangle::Set_By_Length(double sidea, double sideb, double sidec, bool obtuse)
{
    side_a = sidea;
    side_b = sideb;
    side_c = sidec;
    angle_a = Angle_By_Cosine(sidea, sideb, sidec, obtuse);
    angle_b = Angle_By_Cosine(sideb, sidea, sidec, obtuse);
    angle_c = Angle_By_Cosine(sidec, sidea, sideb, obtuse);
    if (Check_Valid_Triangle())
    {
        Set_Triangle_Classification();
        return true;
    }
    return false;
}
bool Triangle::Set_ALL(double angleA, double lengtha, double lengthb, bool obtuse)
{
    angle_a = angleA;
    side_a = lengtha;
    side_b = lengthb;
    double sin_b = std::sin(Degree_To_Radian(angle_a)) * side_b / side_a;
    if (obtuse)
    {
        angle_b = 180 - Radian_To_Degree(std::asin(sin_b));
    }
    else
    {
        angle_b = Radian_To_Degree(std::asin(sin_b));
    }
    angle_c = 180 - angle_a - angle_b;
    side_c = Length_By_Cosine(angle_c, side_a, side_b);
    if (Check_Valid_Triangle())
    {
        Set_Triangle_Classification();
        return true;
    }

    return false;
}
bool Triangle::Set_LLA(double angleA, double lengthb, double lengthc, bool obtuse)
{
    angle_a = angleA;
    side_b = lengthb;
    side_c = lengthc;
    side_a = Length_By_Cosine(angle_a, side_b, side_c);
    angle_b = Angle_By_Cosine(side_b, side_a, side_c, obtuse);
    angle_c = Angle_By_Cosine(side_c, side_a, side_b, obtuse);
    if (Check_Valid_Triangle())
    {
        Set_Triangle_Classification();
        return true;
    }

    return false;
}
bool Triangle::Set_ALA(double angleA, double lengtha, double angleB)
{
    side_a = lengtha;
    angle_a = angleA;
    angle_b = angleB;
    side_b = std::sin(Degree_To_Radian(angle_b)) * side_a / std::sin(Degree_To_Radian(angle_a));
    angle_c = 180 - angle_a - angle_b;
    side_c = Length_By_Cosine(angle_c, side_a, side_b);
    if (Check_Valid_Triangle())
    {
        Set_Triangle_Classification();
        return true;
    }
    return false;
}
/*Private Functions */
bool Triangle::Check_Valid_Triangle()
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
void Triangle::Set_Triangle_Classification()
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

    if (Is_Right_Triangle(side_a, side_b, side_c))
    {
        type_angle = ANGLE_TYPE::RIGHT;
    }
    else if (Is_Obtuse_Angle(angle_a) || Is_Obtuse_Angle(angle_b) || Is_Obtuse_Angle(angle_c))
    {
        type_angle = ANGLE_TYPE::OBTUSE;
    }
    else
    {
        type_angle = ANGLE_TYPE::ACUTE;
    }

    is_set = true;
}
double Triangle::Radian_To_Degree(double radian) const
{
    return (radian * 180) / M_PI;
}
double Triangle::Degree_To_Radian(double degree) const
{
    return (degree * M_PI) / 180;
}
bool Triangle::Is_Right_Triangle(double sidea, double sideb, double sidec)
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
bool Triangle::Is_Obtuse_Angle(double degree)
{
    if (degree > 90)
    {
        return true;
    }
    return false;
}
double Triangle::Angle_By_Cosine(double returnside, double sideb, double sidec, bool obtuse)
{
    double cosine_rule = ((sideb * sideb) + (sidec * sidec) - (returnside * returnside)) / (2 * sideb * sidec);
    double radian_angle = std::acos(cosine_rule);
    // Check if there are multiple solutions
    if (cosine_rule < -1 || cosine_rule > 1)
    {
        // If cosine rule is out of range, there are no valid solutions
        return -1.0;
    }
    else if (cosine_rule == -1 || cosine_rule == 1)
    {
        // If cosine rule is -1 or 1, there is only one valid solution
        return Radian_To_Degree(radian_angle);
    }
    else
    {
        // If cosine rule is between -1 and 1, there are two valid solutions
        if (obtuse)
        {
            return 180 - Radian_To_Degree(radian_angle);
        }
        return Radian_To_Degree(radian_angle);
    }
}
double Triangle::Length_By_Cosine(double angle, double sideb, double sidec)
{
    return std::sqrt(sideb * sideb + sidec * sidec - 2 * sideb * sidec * std::cos(Degree_To_Radian(angle)));
}
/* Public Functions */
void Triangle::Print_Summary() const
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
    std::cout.width(17);
    std::cout << "Angles      : [A]" << std::fixed << angle_a;
    std::cout.precision(2);
    std::cout.width(17);
    std::cout << "[B]" << std::fixed << angle_b;
    std::cout.precision(2);
    std::cout.width(17);
    std::cout << "[C]" << std::fixed << angle_c << std::endl;

    std::cout.precision(2);
    std::cout.width(17);
    std::cout << "Lengths     : [a]" << std::fixed << side_a;
    std::cout.precision(2);
    std::cout.width(17);
    std::cout << "[b]" << std::fixed << side_b;
    std::cout.precision(2);
    std::cout.width(17);
    std::cout << "[c]" << std::fixed << side_c << std::endl;

    std::cout << "Perimeter   : " << Get_Perimeter() << std::endl;

    std::cout << "Area        : " << Get_Area() << std::endl;
    std::cout << "Height a    : " << Get_Height('a') << std::endl;
    std::cout << "Height b    : " << Get_Height('b') << std::endl;
    std::cout << "Height c    : " << Get_Height('c') << std::endl;
    std::cout << "Base Side   : " << Get_Base() << std::endl;

    std::cout << "Inradius    : " << Get_Inradius() << std::endl;
    std::cout << "Circumradius: " << Get_Circumradius() << std::endl;

    std::cout << std::endl;
}

double Triangle::Get_Length(const char side_letter) const
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

double Triangle::Get_Degree_Angle(const char angle_letter) const
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

double Triangle::Get_Radian_Angle(const char angle_letter) const
{
    if (angle_letter == 'A')
    {
        return Degree_To_Radian(angle_a);
    }
    else if (angle_letter == 'B')
    {
        return Degree_To_Radian(angle_b);
    }
    else if (angle_letter == 'C')
    {
        return Degree_To_Radian(angle_c);
    }
    return -1.0;
}

double Triangle::Get_Area() const
{
    double s = Get_Perimeter() / 2.0;
    double Get_Area = sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    return Get_Area;
}

double Triangle::Get_Perimeter() const
{
    return side_a + side_b + side_c;
}

double Triangle::Get_Height(const char angle) const
{
    if (angle == 'a')
    {
        return (2 * Get_Area()) / side_a;
    }
    else if (angle == 'b')
    {
        return (2 * Get_Area()) / side_b;
    }
    else if (angle == 'c')
    {
        return (2 * Get_Area()) / side_c;
    }
    return -1.0;
}

char Triangle::Get_Base() const
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

double Triangle::Get_Inradius() const
{
    return Get_Area() / (Get_Perimeter() / 2);
}

double Triangle::Get_Circumradius() const
{
    return ((side_a * side_b * side_c) / (4 * Get_Area()));
}
