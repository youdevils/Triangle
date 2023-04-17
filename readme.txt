General Purpose Triangle

Can be instanciated in the following ways:
1. Empty
    Is a not set to any meaningful values. Will output error to terminal.
2. Set_By_Length
    Take all three side lengths of a triangle
3. Set_ALL
    (Angle - Length - Length) Where the length following the angle is the angles opposite length and the last lenght is any other
4. Set_LLA
    (Angle - Length - Length) Where the neither length is the opposite of the angle
5. Set_ALA
    (Angle - Length - Angle) Where the length following the angle is the angles opposite length and the last angle is any other
    Note that the 3rd angle can be found for any triangle by adding the other 2 and subtracting from 180.

All Set calls will go through basic validation. Where this fails a console output will show. 
The triangle can be set multiple times with the same or different data, even after a validation fail.

The following functions are available for triangles that have been set and passed validation:

Print_Summary
    Prints triangle information to the console
Get_Length
    Returns the length of a triangle side 'a', 'b' or 'c'
Get_Radian_Angle
    Returns the angle of a triangle vertex 'A', 'B' or 'C' in radians
Get_Degree_Angle
    Returns the angle of a triangle vertex 'A', 'B' or 'C' in degrees
Get_Area
    Returns the area value for the triangle
Get_Perimeter
    Returns the perimeter value for the triangle
Get_Height
    Returns the height of a triangles vertex 'A', 'B' or 'C' to its opposite side
Get_Base
    Returns a side of triangle that can be used as the base
Get_Inradius
    Returns the radius value of the triangles inradius circle
Get_Circumradius
    Returns the radius value of the triangles circumradius circle
