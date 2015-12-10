#include <iostream>
#include <string>
#include <set>

using namespace::std;

class Sales_item {
friend void new_item(istream &, Sales_item &);
public:
    Sales_item(const string &s, const int price):units_sold(1), revenue(price) {
        isbn.insert(s);
    }
    void get_item() {
        for (set<string>::iterator iter = isbn.begin(); iter != isbn.end(); ++iter)
        {
            cout << *iter << endl;
        }
        cout << units_sold << " " << revenue << endl;
    };
private:
    set<string> isbn;
    int units_sold;
    double revenue;
};

void new_item(istream &in, Sales_item &item)
{
    string isbn;
    int price;
    in >> isbn >> price;
    item.isbn.insert(isbn);
    item.revenue += price;
    item.units_sold++;
}

int main()
{
    Sales_item cpp("c++ primer", 20);

    new_item(cin, cpp);
    cpp.get_item();

    return 0;
}
