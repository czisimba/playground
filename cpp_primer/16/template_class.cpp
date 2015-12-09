#include <iostream>
#include <string>

using namespace::std;

template <class TYPE> class Tem {
};

int main()
{
    Tem<int> tm0;
    cout << &tm0 << endl;

    return 0;
}
