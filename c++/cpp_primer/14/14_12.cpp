#include <iostream>

using namespace::std;

class Sales_item {
    friend Sales_item operator+(Sales_item &, Sales_item &);
public:
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
Sales_item operator+(Sales_item &it1, Sales_item &it2)
{
    if (it1.isbn == it2.isbn)
    {
        it1.revenue = (it1.revenue * it1.units_sold + it2.revenue * it2.units_sold) / (it1.units_sold + it2.units_sold);
        it1.units_sold += it2.units_sold;//it.units_sold is total sold now
    }
    return it1;
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
    it1 += it2;
    cout << it1.isbn << "\t" << it1.units_sold << "\t" << it1.revenue << endl;
    cout << it2.isbn << "\t" << it2.units_sold << "\t" << it2.revenue << endl;

    return 0;
}
