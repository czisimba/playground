#include <iostream>
#include "12_8.h"

using namespace::std;

inline double Sales_item:: avg_price() const {
    if (units_sold != 0)
        return revenue / units_sold;
    else
        return 0;
};

int main()
{
    Sales_item si;
    cout << si.avg_price() << endl;

    return 0;
}
