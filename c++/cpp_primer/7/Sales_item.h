#include <iostream>
using namespace::std;

class Sales_item {
    public:
        double avg_price(const Sales_item &rhs);
        bool same_isbn(const Sales_item &rhs) const
        {
            return isbn == rhs.isbn;
        }
        void print_revenue() const
        {
            cout << revenue << endl;
        }
        Sales_item(): units_sold(1), revenue(3.0) 
        {
        }

    private:
        string isbn;
        unsigned units_sold;
        double revenue;
};
