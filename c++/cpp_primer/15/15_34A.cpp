#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>

using namespace::std;

class Item_Base {
public:
    Item_Base(const string &name, const size_t us, const double pr):isbn(name),units_sold(us),price(pr) {
    }
    virtual Item_Base * clone() const {
        return new Item_Base(*this);
    }
    virtual void debug(bool open) const {
        if (open)
            cout << "Item_Base:isbn:" << isbn << "]\tunits_sold[" << units_sold << "]\tprice:[" << price << "]" << endl;
    }
    virtual double net_price();
    virtual ~Item_Base() {
    }
protected:
    string isbn;
    size_t units_sold;
    double price;
private:
};

class Bulk_item:public Item_Base {
public:
    Bulk_item(const string &name, const size_t us, const double pr, const size_t m, double rt):Item_Base(name, us, pr),mtq(m),rate(rt) {
    }
    virtual Bulk_item* clone() const {
        return new Bulk_item(*this);
    }
    void debug(bool open) const {
        if (open)
            cout << "Bulk_item:isbn:" << isbn << "]\tunits_sold[" << units_sold << "]\tprice:[" << price << "]\tmtq:[" \
                << mtq << "]\trate[" << rate << "]" << endl;
    }
    double net_price();
protected:
    size_t mtq;
    double rate;
};

class Sales_item {
public:
    Sales_item():p(0), use(new size_t (1)) {
    }
    Sales_item(Item_Base &);
    Sales_item(Sales_item &i):p(i.p),use(i.use) {
        ++*use;
    }
    ~Sales_item() {
        des_use();
    }
    Sales_item &operator=(Sales_item &);
    Item_Base *operator->() {
        if (p)
            return p;
        else
            throw logic_error("unbound Sales_item");
    }
    Item_Base &operator*() {
        if (p)
            return *p;
        else
            throw logic_error("unbound Sales_item");
    }
private:
    Item_Base *p;
    size_t *use;
    void des_use() {
        --*use;
        if (*use == 0) {
            delete p;
            delete use;
        }
    }
};

double Item_Base::net_price() {
    return units_sold * price;
}
double Bulk_item::net_price() {
    size_t no_cheap,cheap;
    if (units_sold > mtq)
    {
        no_cheap = mtq;
        cheap = units_sold - mtq;
    }
    else
    {
        no_cheap = units_sold;
        cheap = 0;
    }
    return no_cheap * price + cheap * price * rate;
}
Sales_item::Sales_item(Item_Base &ib):p(ib.clone()),use(new size_t(1)) {
}
Sales_item &Sales_item::operator=(Sales_item &rhs) {
    ++*rhs.use;
    des_use();
    p = rhs.p;
    use = rhs.use;
    return *this;
}

int main()
{
    Item_Base base("cpp_primer", 10, 12.5);
    Bulk_item item("cpp_primer", 10, 12.5, 5, 0.8);
    Sales_item si(item);
    base.debug(false);
    item.debug(false);
    cout << item.net_price() << endl;
    cout << si->net_price() << endl;

    return 0;
}
