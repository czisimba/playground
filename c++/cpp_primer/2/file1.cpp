#include <iostream>
#include "file2.h"

extern const int value = 100;
int dval = 1024;
const int &ref = dval + 34;

int main()
{
    print_value();
    std::cout << "ref:" << ref << std::endl;
    dval = 3;
    std::cout << "ref:" << ref << std::endl;

    return 0;
}
