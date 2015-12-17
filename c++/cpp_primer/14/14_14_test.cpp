#include <iostream>
#include <string>

using namespace::std;

class Sales_item {
public:
    Sales_item &operator=(Sales_item &);
private:
    string isbn;
    int units_sold;
    double revenue;
};

Sales_item &Sales_item::operator=(Sales_item &it) {
    isbn = it.isbn;
    return *this;
}

int main()
{
    Sales_item it1;
    Sales_item it2;
    it2 = it1;

    return 0;
}
