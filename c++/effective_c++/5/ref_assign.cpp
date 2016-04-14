#include <iostream>
#include <string>

class C {
public:
    C():v4(0) {  };
    int v1;
    static int v2;
    static const int v3 = 4;//static const int can init in class
    const int v4;
    //static const std::string v5 = "cz"; // static const string cant't initin class
};
int C::v2 = 3;//static must init outside class

int main()
{
    int i = 3,j = 4;
    int &r = i;
    r = j;// same ass i = j,not change r refer to j
    std::cout << "i:" << i << " j:" << j << std::endl;

    int k = 3, *p;// operator near to value,looks clear
    p = &k;
    std::cout << "k:" << k << " p:" << p << std::endl;

    C c;
    c.v1 = 1;
    C::v2 = 2;
    std::cout << "v1:" << c.v1 << " v2:" << c.v2 << " v3:" << c.v3 << std::endl;
    c.v1 = 3;
    c.v2 = 4;
    std::cout << "v1:" << c.v1 << " v2:" << c.v2 << " v3:" << c.v3 << std::endl;

    return 0;
}
