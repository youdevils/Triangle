General Purpose Triangle

Can be instanciated in the following ways:
1. Empty
    Is not set to any meaningful values. Will be in this state if validation fails.

Once triangle object is instanciated, these functions create the triangle data from various inputs
1. Set_By_Length
    Take all three side lengths of a triangle
2. Set_ALL
    (Angle - Length - Length) Where the length following the angle is the angles opposite length and the last lenght is any other
3. Set_LLA
    (Angle - Length - Length) Where the neither length is the opposite of the angle
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
