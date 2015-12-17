//
//  main.cpp
//  15_6
//
//  Created by nichola on 15/11/30.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>

using namespace::std;

class Item_Base {
public:
    Item_Base(const string nm, const double pr):isbn(nm),price(pr) {
    }
    double net_price(const size_t num) {
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
    Bulk_Item(const string nm, const double pr, const size_t mq, const double dc):Item_Base(nm, pr),min_qty(mq),discount(dc) {
    }
    double net_price(const size_t num) {
        size_t no_qty_num = num,qty_num = 0;
        if (num > min_qty) {
            no_qty_num = min_qty;
            qty_num = num - min_qty;
        }
        
        return (no_qty_num * price + qty_num * price * discount);//sum price
    }
private:
    size_t min_qty;
    double discount;
};

int main(int argc, const char * argv[]) {
    Bulk_Item bi("cpp_primer", 20, 10, 0.9);
    cout << bi.net_price(20) << endl;
    
    return 0;
}