#include <iostream>
#include <string>
#include <bitset>
using std::string;
using std::bitset;

int main()
{
    string s("");
    bitset<32> b;

    b[1] = 1;
    b[2] = 1;
    b[3] = 1;
    b[5] = 1;
    b[8] = 1;
    b[13] = 1;
    b[21] = 1;
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
