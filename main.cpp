#include "Triangle.hpp"

int main()
{
    Triangle t1;
    t1.Set_ALL(40, 65.659, 90, true);
    t1.Print_Summary();
    t1.Set_LLA(40, 100, 90, false);
    t1.Print_Summary();
}