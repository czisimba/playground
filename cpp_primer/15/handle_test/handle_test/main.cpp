//
//  main.cpp
//  handle_test
//
//  Created by nichola on 15/12/1.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdexcept>

using namespace::std;

class Item_Base {
public:
    Item_Base(const string nm, const double pr):isbn(nm),price(pr) {
    }
    virtual Item_Base* clone() const {
        return new Item_Base(*this);
    }
    virtual double net_price(const size_t num) {
        return price * num;
    }
    virtual ~Item_Base() {
    }
private:
    string isbn;
protected:
    double price;
};

class Bulk_Item:public Item_Base {
public:
    Bulk_Item(const string nm, const double pr, const size_t mq, const double dc):Item_Base(nm, pr),max_qty(mq),discount(dc) {
    }
    Bulk_Item* clone() const {
        return new Bulk_Item(*this);
    }
    virtual double net_price(const size_t num) {
        size_t no_qty_num = 0,qty_num = num;
        if (num > max_qty) {
            no_qty_num = num - max_qty;
            qty_num = max_qty;
        }
        
        return (no_qty_num * price + qty_num * price * discount);//sum price
    }
private:
    size_t max_qty;
    double discount;
};

class Sales_item {
public:
    Sales_item():p(0),use(new size_t(1)) {
    }
    Sales_item(const Item_Base &item):p(item.clone()),use(new size_t(1)) {
    }
    Sales_item(const Sales_item &rhs):p(rhs.p),use(rhs.use) {
        ++*use;
    }
    Item_Base &operator* () {
        if (p)
            return *p;
        else
            throw logic_error("unbound Sales_item");
    }
    Item_Base *operator-> () {
        if (p)
            return p;
        else
            throw logic_error("unbound Sales_item");
    }
    Sales_item &operator= (Sales_item &rhs) {
        ++*rhs.use;
        des_use();
        p = rhs.p;
        ++*use;
        return *this;
    }
    ~Sales_item() {
        des_use();
    }
private:
    Item_Base *p;
    size_t *use;
    void des_use() {
        --*use;
        if (*use == 0)
        {
            delete p;
            delete use;
        }
    }
};

int main(int argc, const char * argv[]) {
    Bulk_Item bi("cpp_primer", 20, 10, 0.9);
    cout << bi.net_price(10) << endl;
    
    return 0;
}
