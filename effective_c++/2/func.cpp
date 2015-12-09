#include <iostream>

// template inline function:fast,type safety,expective
template <typename T> inline T 
GetMax(const T& a,const T& b)
{
    return a > b ? a : b;
}
int main()
{
    int a = 3, b = 5;
    std::cout << GetMax(a,b) << std::endl;

    return 0;
}
