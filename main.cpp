#include "Triangle.hpp"

int main()
{
    /*
    Angle Length Angle
    Scalene triangle: (30°, 8, 60°)
    Isosceles triangle: (45°, 10, 45°)
    Equilateral triangle: (60°, 5, 60°)
    Right-angled triangle: (30°, 6, 90°)
    Obtuse triangle: (40°, 7, 100°)
    */

    Triangle t1;
    t1.Set_ALA(30, 8, 60);
    t1.Print_Summary();
    /*
    Angle Length Length
    Scalene triangle: (50°, 7, 9)
    Isosceles triangle: (60°, 5, 5)
    Equilateral triangle: (60°, 6, 6)
    Right-angled triangle: (30°, 3, 6)
    Obtuse triangle: (100°, 8, 7)
    Degenerate triangle: (120°, 1, 2)

    Triangle t1;
    t1.Set_ALL(50, 7, 9, false);
    t1.Print_Summary();
    t1.Set_ALL(50, 7, 9, true);
    t1.Print_Summary();

    t1.Set_ALL(60, 5, 5, false);
    t1.Print_Summary();
    // Fails no obtuse.
    t1.Set_ALL(60, 5, 5, true);
    t1.Print_Summary();
*/
    /*
  By Length Tests
  Scalene triangle: (7, 8, 9)
  Isosceles triangle: (5, 5, 7)
  Equilateral triangle: (6, 6, 6)
  Right-angled triangle: (3, 4, 5)
  Obtuse triangle: (7, 8, 12)
  Degenerate triangle: (1, 2, 3)

  Triangle t3;
  t3.Set_By_Length(7, 8, 9);
  t3.Print_Summary();
  t3.Set_By_Length(5, 5, 7);
  t3.Print_Summary();
  t3.Set_By_Length(6, 6, 6);
  t3.Print_Summary();
  t3.Set_By_Length(3, 4, 5);
  t3.Print_Summary();
  t3.Set_By_Length(7, 8, 12);
  t3.Print_Summary();
  t3.Set_By_Length(1, 2, 3);
  t3.Print_Summary();
  */
}