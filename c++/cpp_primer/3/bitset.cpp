#include <iostream>
#include <string>
#include <bitset>
using std::string;
using std::bitset;

int main()
{
    string str("11001100");
    bitset<32> b(str, 0, 7);
    std::cout << str << std::endl;

    for (int idx = 31;idx != -1;idx--)
        std::cout << b[idx] << " ";
    std::cout << std::endl;

    std::cout << "any():" << b.any() << std::endl;
    std::cout << "none():" << b.none() << std::endl;
    std::cout << "count():" << b.count() << std::endl;
    std::cout << "size():" << b.size() << std::endl;
    std::cout << "flip():" << b.flip() << std::endl;
    std::cout << "count():" << b.count() << std::endl;

    return 0;
}
