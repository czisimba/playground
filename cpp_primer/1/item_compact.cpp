#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item,total;

    std::cin >> total;
    while (std::cin >> item)
    {
        if (total.same_isbn(item))
            total += item;
        else
        {
            std::cout << "sum item is :" << std::endl;
            std::cout << total << std::endl;
            total = item;
        }
    }

    return 0;
}
