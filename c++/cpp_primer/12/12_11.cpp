#include <iostream>

using namespace::std;

class X;


class Y {
    X x;
public:
    Y(X &rx):x(rx) {
    }
    Y():x(0){
    }
};

class X {
    Y *y_ptr;
public:
    X(Y *ry):y_ptr(ry) {
    }
};

int main()
{
    Y y;
    X x(&y);

    return 0;
}
