#include <iostream>
#include "Sales_item.h"

using namespace::std;

int main()
{
    Sales_item item1,item2;
    cout << item1.same_isbn(item2) << endl;
    cout << "item1\'s revenue:" << endl;
    item1.print_revenue();
    cout << item1.avg_price(item2) << endl;
    cout << "item1\'s revenue:" << endl;
    item1.print_revenue();

    return 0;
}
