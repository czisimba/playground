#include <iostream>

int main()
{
    int i = 50,sum = 0;
    
    while (i < 101)
    {
        sum += i;
        i++;
    }
    std::cout << "sum of 50 to 100 is: " << sum << std::endl;

    return 0;
}
