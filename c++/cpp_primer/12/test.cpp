#include <iostream>

using namespace::std;

void check(const int &v)
{
    cout << v << endl;
}

/*
void check(int v)
{
    cout << v << endl;
}
*/

int main()
{
    int val = 3;
    check(val);
    check(3);

    return 0;
}
