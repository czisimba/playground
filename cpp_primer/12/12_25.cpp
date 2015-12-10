#include <iostream>
#include <string>

using namespace::std;

class Sales_item {
public:
    string isbn;
    int units_sold;
    int revenue;
    int arr[10];
    Sales_item(const string &book = ""):isbn(book),units_sold(0),revenue(0) {
    }
    Sales_item(const istream &in = cin) {
    }
};

int main()
{
    Sales_item item("mybook");
    Sales_item item_cin(cin);

    cout << item_cin.isbn << endl;
    cout << item_cin.units_sold << endl;
    cout << item_cin.revenue << endl;
    cout << item_cin.arr[0] << endl;

    return 0;
}
