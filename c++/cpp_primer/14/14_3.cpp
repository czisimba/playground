#include <iostream>

using namespace::std;

class Sales_item {
    friend Sales_item operator+(Sales_item &, Sales_item &);
public:
    Sales_item(const string &is = ""):name(is), price(0) {
    }
    Sales_item &operator+=(const Sales_item &it)
    {
        price += it.price;
        return *this;
    }
private:
    string name;
    int price;
};

Sales_item operator+(Sales_item &it1, Sales_item &it2)
{
    Sales_item item_sum;
    item_sum.price = it1.price + it2.price;

    return item_sum;
}

int main()
{
    string null_book = "999-999";
    //Sales_item item(cin);
    //Sales_item item(null_book);
    Sales_item item(null_book);
    item += null_book;
    //item += null_book;

    return 0;
}
