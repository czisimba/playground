#include <iostream>

int main()
{
    int val,cnt = 0;
    std::cout << "end some number(include some negative)" << std::endl;
    while (std::cin >> val)
        cnt += val < 0 ? 1 : 0; 
    std::cout << "negative count is: " << cnt << std::endl;

    return 0;
}
