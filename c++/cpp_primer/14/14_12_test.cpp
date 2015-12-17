#include <iostream>

using namespace::std;

class Sales_item {
public:
    Sales_item operator+(Sales_item &);
    Sales_item(const string &ib = "", const int us = 0, const double rev = 0):isbn(ib),units_sold(us),revenue(rev) {
    }
    bool same_isbn(Sales_item &rhs) {
        return rhs.isbn == isbn;
    }
    //Sales_item operator+(Sales_item &, Sales_item &);
    Sales_item &operator+=(Sales_item &it1);
    string isbn;
    int units_sold;
    double revenue;
private:
};
Sales_item Sales_item::operator+(Sales_item &it2)
{
    Sales_item new_item;
    if (isbn == it2.isbn)
    {
        new_item.revenue = (revenue * units_sold + it2.revenue * it2.units_sold) / (units_sold + it2.units_sold);
        new_item.units_sold = units_sold + it2.units_sold;//it.units_sold is total sold now
    }
    return new_item;
}

Sales_item &Sales_item::operator+=(Sales_item &it1) {
    *this = *this + it1;
    return *this;
}

int main()
{
    Sales_item it1("cpp", 10, 100);
    Sales_item it2("cpp", 7, 300.1);
    cout << it1.isbn << "\t" << it1.units_sold << "\t" << it1.revenue << endl;
    cout << it2.isbn << "\t" << it2.units_sold << "\t" << it2.revenue << endl;
    Sales_item &it3 = (it1 += it2);
    cout << it1.isbn << "\t" << it1.units_sold << "\t" << it1.revenue << endl;
    cout << it2.isbn << "\t" << it2.units_sold << "\t" << it2.revenue << endl;
    cout << it3.isbn << "\t" << it3.units_sold << "\t" << it3.revenue << endl;


    return 0;
}
