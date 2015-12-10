//
//  main.cpp
//  15_26
//
//  Created by nichola on 15/12/1.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>

using namespace::std;

class Item_Base {
public:
    Item_Base(const string nm, const double pr):isbn(nm),price(pr) {
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

class Disc_Item:public Item_Base {
public:
    virtual double net_price(const size_t num) const = 0;

};

class Bulk_Item:public Disc_Item {
public:
    Bulk_Item(const string nm, const double pr, const size_t mq, const double dc):Item_Base(nm, pr),max_qty(mq),discount(dc) {
    }
    virtual double net_price(const size_t num) {
        size_t no_qty_num = 0,qty_num = num;
        if (num > max_qty) {
            no_qty_num = num - max_qty;
            qty_num = max_qty;
        }
        
        return (no_qty_num * price + qty_num * price * discount);//sum price
    }
    
    
};

int main(int argc, const char * argv[]) {
    Bulk_Item bi("cpp_primer", 20, 10, 0.9);
    cout << bi.net_price(10) << endl;
    
    return 0;
}
