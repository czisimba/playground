#include <iostream>

int main()
{
    int i,v1,v2,lower,upper,sum = 0;

    std::cout << "Enter two number" << std::endl;
    std::cin >> v1 >> v2;
    if (v1 > v2)
    {
        lower = v2;
        upper = v1;
    }
    else
    {
        lower = v1;
        upper = v2;
    }

    for (i = lower;i < upper + 1;i++)
        sum += i;
    std::cout << "sum from lower[" << lower << "],upper[" << 
        upper << "] is :" << sum << std::endl;

    return 0;
}
