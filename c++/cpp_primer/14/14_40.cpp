#include <iostream>
#include <string>

using namespace::std;

class Sales_item {
public:
    Sales_item(const string ib = "", const double rev = 0.0):isbn(ib),revenue(rev) {
    }
    operator string() const {
        return isbn;
    }
    operator double() const {
        return revenue;
    }
private:
    string isbn;
    double revenue;
};

int main()
{
    Sales_item si("cpp", 12.3);
    cout << string(si) << endl;
    cout << double(si) << endl;

    return 0;
}
