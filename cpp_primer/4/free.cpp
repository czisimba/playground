#include <iostream>
using namespace::std;

int main()
{
    int *pa = new int[100];

    delete [] pa;

    return 0;
}
