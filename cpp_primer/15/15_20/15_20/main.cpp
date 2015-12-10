//
//  main.cpp
//  15_20
//
//  Created by nichola on 15/11/30.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>

using namespace::std;

class Item_Base {
public:
    Item_Base(const string nm = "", const double pr = 0):isbn(nm),price(pr) {
        cout << "Item_Base(const string nm, const double pr)" << endl;
    }
    Item_Base(const Item_Base &rhs) {
        cout << "Item_Base(const Item_Base &rhs)" << endl;
    }
    Item_Base &operator=(const Item_Base &rhs) {
        cout << "Item_Base &operator=(const Item_Base &rhs)" << endl;
        return *this;
    }
    double net_price(const size_t num) {
        return price * num;
    }
    virtual ~Item_Base() {
        cout << "virtual ~Item_Base()" << endl;
    }
private:
    string isbn;
protected:
    double price;
};

class Bulk_Item:public Item_Base {
public:
    Bulk_Item(const string nm = "", const double pr = 0, const size_t mq = 0, const double dc = 0.0):Item_Base(nm, pr),max_qty(mq),discount(dc) {
        cout << "Bulk_Item(const string nm, const double pr, const size_t mq, const double dc)" << endl;
    }
    Bulk_Item(const Bulk_Item &rhs):Item_Base(rhs) {
        cout << "Bulk_Item(const Bulk_Item &rhs)" << endl;
    }
    Bulk_Item &operator=(const Bulk_Item &rhs) {
        cout << "Bulk_Item &operator=(const Bulk_Item &rhs)" << endl;
        return *this;
    }
    virtual ~Bulk_Item() {
        cout << "virtual ~Bulk_Item()" << endl;
    }
    double net_price(const size_t num) {
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
void func1(Item_Base ib)
{
}
void func2(Item_Base &ib)
{
}
Item_Base func3()
{
    Item_Base obj;
    return obj;
}

int main(int argc, const char * argv[]) {
    Item_Base ib;
    func1(ib);
    func2(ib);
    ib = func3();
    Item_Base *p = new Item_Base();
    delete p;
    Item_Base *p1 = new Bulk_Item();
    delete p1;
    Bulk_Item *p3 = new Bulk_Item();
    delete p3;
    
    
    
    return 0;
}
