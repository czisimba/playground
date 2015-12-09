#include <iostream>

using namespace::std;

class Check_Bool {
public:
    int operator() (bool expr, int v1, int v2) {
        if (expr)
            return v1;
        else 
            return v2;
    }
};

int main()
{
    bool b = 1;
    int v1 = 3;
    int v2 = 2;
    Check_Bool cb;
    cout << cb(b, v1, v2) << endl;

    return 0;
}
