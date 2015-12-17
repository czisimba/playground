#include <iostream>

class static_cls {
public:
    static const int si = 3;// define and init,may be not support by old compile
};

class static_cls1 {
public:
    static const int si;// define
};
const int static_cls1::si = 4;// init

class enum_cls {
public:
    enum { si = 5};// enum hack
};

int main()
{
    static_cls c;
    std::cout << c.si << std::endl;
    static_cls1 c1;
    std::cout << c1.si << std::endl;
    enum_cls c2;
    std::cout << c2.si << std::endl;

    return 0;
}
