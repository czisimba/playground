#include <iostream>

using namespace::std;

class Sales_item {
    friend Sales_item operator+(const Sales_item &, const Sales_item &); 
    friend ostream &operator<<(ostream &, const Sales_item &); 
    friend istream &operator>>(istream &, const Sales_item &); 
public:
    Sales_item &operator+=(const Sales_item &);
private:
    int price;
};

Sales_item operator+(const Sales_item &s1, const Sales_item &s2) {
    Sales_item tmp;
    tmp.price = s1.price + s2.price;
    return tmp;
}

ostream &operator<<(ostream &, const Sales_item &); 
istream &operator>>(istream &, const Sales_item &); 

int main()
{
    Sales_item item1, item2;
    Sales_item item_sum = operator+(item1 , item2);

    return 0;
}
