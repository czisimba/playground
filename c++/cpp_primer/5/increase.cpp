#include <iostream>

using namespace::std;

int main()
{
    int x = 1, y = 2;
    cout << x << " " << y << endl;
    x = (x + 3)++;
    cout << x << " " << y << endl;

    return 0;
}
