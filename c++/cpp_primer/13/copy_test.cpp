#include <iostream>

using namespace::std;

class NoName {
public:
    int ival;
};

int main()
{
    NoName n0;
    n0.ival = 1;
    NoName n1 = n0;
    cout << n1.ival << endl;

    return 0;
}
