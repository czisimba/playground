#include <string>

class Item_Base {
    public:
        Item_Base(const std::string nm, const double pr):isbn(nm),price(pr) {
        }
        double net_price(const size_t num) {
            return price * num;
        }
        virtual ~Item_Base() { 
        }
    private:
        std::string isbn;
        //protected:
        double price;
};
