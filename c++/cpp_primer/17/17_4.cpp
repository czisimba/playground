#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main()
{
    try {
        throw std::runtime_error("bad program!");
    }
    catch (const std::exception &c) {
        std::cerr << c.what() << std::endl;
        abort();
    }
    return 0;
}
