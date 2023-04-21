General Purpose Triangle

Can be instanciated in the following ways:
1. Empty
    Is not set to any meaningful values. Will be in this state if validation fails.

Once triangle object is instanciated, these functions create a full triangle with supporting data from various inputs
1. Set_By_Length
    Take all three side lengths of a triangle
    True/False must be passed to confirm if the output should be acute or obtuse
2. Set_ALL
    (Angle - Length - Length) Where the length following the angle is the angles opposite length and the last lenght is any other
    True/False must be passed to confirm if the output should be acute or obtuse
3. Set_LLA
    (Angle - Length - Length) Where the neither length is the opposite of the angle
    True/False must be passed to confirm if the output should be acute or obtuse
4. Set_ALA
    (Angle - Length - Angle) Where the length following the angle is the angles opposite length and the last angle is any other

Set functions must validate that inputs are a triangle. 
Validation failure shown in console.

The triangle can be set multiple times with the same or different data, even after a validation fail.

The following functions are available for triangles that have been set and passed validation:
[Print_Summary]
    Prints triangle information to the console
[Get_Length]
    Returns the length of a triangle side 'a', 'b' or 'c'
[Get_Radian_Angle]
    Returns the angle of a triangle vertex 'A', 'B' or 'C' in radians
[Get_Degree_Angle]
    Returns the angle of a triangle vertex 'A', 'B' or 'C' in degrees
[Get_Area]
    Returns the area value for the triangle
[Get_Perimeter]
    Returns the perimeter value for the triangle
[Get_Height]
    Returns the height of a triangles vertex 'A', 'B' or 'C' to its opposite side
[Get_Base]
    Returns a side of triangle that can be used as the base
[Get_Inradius]
    Returns the radius value of the triangles inradius circle
[Get_Circumradius]
    Returns the radius value of the triangles circumradius circle


Example Usage:
#include "Triangle.hpp"

int main()
{
    Triangle t1;
    t1.Set_ALL(40, 65.659, 90, true);
    t1.Print_Summary();
    t1.Set_LLA(40, 100, 90, true);
    t1.Print_Summary();
    t1.Set_LLA(40, 100, 90, false);
    t1.Print_Summary();

    Triangle t2;
    t2.Set_By_Length(3, 4, 5, false);
    t2.Print_Summary();
}

Exmaple Output and Data
Types       : Obtuse | Scalene
Angles      : [A]40.00              [B]118.23             [C]21.77
Lengths     : [a]65.66              [b]90.00              [c]37.89
Perimeter   : 193.55
Area        : 1095.97
Height a    : 33.38
Height b    : 24.35
Height c    : 57.85
Base Side   : a
Inradius    : 11.33
Circumradius: 51.07

Types       : Obtuse | Scalene
Angles      : [A]40.00              [B]101.77              [C]118.23
Lengths     : [a]65.66              [b]100.00              [c]90.00
Perimeter   : 255.66
Area        : 2892.54
Height a    : 88.11
Height b    : 57.85
Height c    : 64.28
Base Side   : a
Inradius    : 22.63
Circumradius: 51.07

Types       : Acute | Scalene
Angles      : [A]40.00              [B]78.23              [C]61.77
Lengths     : [a]65.66              [b]100.00             [c]90.00
Perimeter   : 255.66
Area        : 2892.54
Height a    : 88.11
Height b    : 57.85
Height c    : 64.28
Base Side   : a
Inradius    : 22.63
Circumradius: 51.07

Types       : Right | Scalene
Angles      : [A]36.87             [B]53.13             [C]90.00
Lengths     : [a]3.00              [b]4.00              [c]5.00
Perimeter   : 12.00
Area        : 6.00
Height a    : 4.00
Height b    : 3.00
Height c    : 2.40
Base Side   : a
Inradius    : 1.00
Circumradius: 2.50