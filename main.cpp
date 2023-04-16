#include "Triangle.hpp"

int main()
{
    Triangle t1;
    t1.Set_ALL(35, 6, 8, true);
    t1.print_summary();
    t1.Set_ALL(35, 6, 8, false);
    t1.print_summary();
    t1.Set_By_3(2, 2, sqrt(8));
    t1.print_summary();
    t1.Set_By_3(5, 5, 6.467932);
    t1.print_summary();
    t1.Set_By_3(5, 5, 25);
    t1.print_summary();
}