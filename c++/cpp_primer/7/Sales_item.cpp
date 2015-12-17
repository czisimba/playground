#include "Sales_item.h"

double Sales_item::avg_price(const Sales_item &rhs)
{
    ++units_sold;
    if (units_sold)
        return (revenue + rhs.revenue) / units_sold;
    else
        return 0;
}
