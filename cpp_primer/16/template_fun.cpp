#include <iostream>

using namespace::std;

template <typename T> T compare(T &v1,T &v2) {
    return v1 < v2 ? v2 : v1;
}

int main()
{
    double v1 = 0.3,v2 = 3.7;
    cout << compare(v1, v2) << endl;

    return 0;
}
