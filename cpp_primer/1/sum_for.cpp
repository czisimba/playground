#include <iostream>

int main()
{
    int i,sum = 0;
    
    for (i = 50;i < 101;i++)
        sum += i;
    std::cout << "sum of 50 to 100 is: " << sum << std::endl;

    return 0;
}
