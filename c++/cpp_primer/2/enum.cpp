#include <iostream>

int main()
{
    enum points { point2d = 2,point2w,point3d = 3,point3w };
    point3d = point2d;
    std::cout << point3d << std::endl;

    return 0;
}
