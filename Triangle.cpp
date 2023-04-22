#include "Triangle.hpp"

/* Construct Area */
bool Triangle::Set_Lengths(double sidea, double sideb, double sidec)
{
    Sort_Lengths(sidea, sideb, sidec);
    Set_Triangle_Classification();

    if (Check_Valid_Triangle())
    {
        return true;
    }
    return false;
}
bool Triangle::Set_AngleA_Lengtha_Lengthx(double angleA, double lengtha, double lengthb, bool obtuse)
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

    return Triangle::Set_Lengths(side_a, side_b, side_c);
}
bool Triangle::Set_AngleA_Lengthb_Lengthc(double angleA, double lengthb, double lengthc)
{
    angle_a = angleA;
    side_b = lengthb;
    side_c = lengthc;
    side_a = Length_By_Cosine(angle_a, side_b, side_c);
    return Triangle::Set_Lengths(side_a, side_b, side_c);
}
bool Triangle::Set_AngleA_Lengtha_Anglex(double angleA, double lengtha, double angleB)
{
    angle_a = angleA;
    angle_b = angleB;
    angle_c = 180 - angle_a - angle_b;

    side_a = lengtha;
    side_b = std::sin(Degree_To_Radian(angle_b)) * side_a / std::sin(Degree_To_Radian(angle_a));
    side_c = std::sin(Degree_To_Radian(angle_c)) * side_a / std::sin(Degree_To_Radian(angle_a));

    return Triangle::Set_Lengths(side_a, side_b, side_c);
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
        // is_set = false;
        return false;
    }

    return true;
}
void Triangle::Set_Triangle_Classification()
{
    is_set = true;

    if (std::fabs(side_a * side_a - (side_b * side_b + side_c * side_c)) < equivalence_tolerance)
    {
        angle_type = ANGLE_TYPE::RIGHT;
    }
    else if (side_a * side_a < (side_b * side_b + side_c * side_c))
    {
        angle_type = ANGLE_TYPE::ACUTE;
    }
    else if (side_a * side_a > (side_b * side_b + side_c * side_c))
    {
        angle_type = ANGLE_TYPE::OBTUSE;
    }

    if (std::fabs(side_a - side_b) < equivalence_tolerance && std::fabs(side_b - side_c) < equivalence_tolerance)
    {
        side_type = SIDE_TYPE::EQUILATERAL;
    }
    else if (std::fabs(side_a - side_b) > equivalence_tolerance && std::fabs(side_a - side_c) > equivalence_tolerance && std::fabs(side_b - side_c) > equivalence_tolerance)
    {
        side_type = SIDE_TYPE::SCALENE;
    }
    else
    {
        side_type = SIDE_TYPE::ISOSCELES;
    }
}

void Triangle::Sort_Lengths(double sidea, double sideb, double sidec)
{
    double sides[] = {sidea,
                      sideb,
                      sidec};

    if (sides[0] < sides[2])
    {
        double temp = sides[0];
        sides[0] = sides[2];
        sides[2] = temp;
    }

    if (sides[0] < sides[1])
    {
        double temp = sides[0];
        sides[0] = sides[1];
        sides[1] = temp;
    }

    side_a = sides[0];
    side_b = sides[1];
    side_c = sides[2];

    Set_Vertex_Angles();
}

bool Triangle::Set_Vertex_Angles()
{
    if (angle_type == ANGLE_TYPE::RIGHT)
    {
        angle_a = 180 - Angle_By_Cosine(side_a, side_b, side_c);
    }
    else
    {
        angle_a = Angle_By_Cosine(side_a, side_b, side_c);
    }
    angle_b = Angle_By_Cosine(side_b, side_a, side_c);
    angle_c = Angle_By_Cosine(side_c, side_a, side_b);
    return false;
}

double Triangle::Radian_To_Degree(double radian) const
{
    return (radian * 180) / M_PI;
}
double Triangle::Degree_To_Radian(double degree) const
{
    return (degree * M_PI) / 180;
}

double Triangle::Angle_By_Cosine(double returnside, double sideb, double sidec)
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
        return Radian_To_Degree(radian_angle);
        // return Radian_To_Degree(radian_angle);
    }
}
double Triangle::Length_By_Cosine(double angle, double sideb, double sidec)
{
    return std::sqrt(sideb * sideb + sidec * sidec - 2 * sideb * sidec * std::cos(Degree_To_Radian(angle)));
}
/* Public Functions */
void Triangle::Get_Summary() const
{
    if (is_set == false)
    {
        std::cout << "Triangle Not Set." << std::endl
                  << std::endl;
        return;
    }
    std::cout << "Types       : ";
    switch (angle_type)
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

    switch (side_type)
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
    std::cout << "Base Side   : " << Get_Base_Side() << std::endl;

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

char Triangle::Get_Base_Side() const
{
    switch (side_type)
    {
    case SIDE_TYPE::EQUILATERAL:
        return 'a';
        break;
    case SIDE_TYPE::ISOSCELES:
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
