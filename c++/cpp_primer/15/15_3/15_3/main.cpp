//
//  main.cpp
//  15_3
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

int main(int argc, const char * argv[]) {
    Item_Base ib("cpp_primer", 15);
    cout << ib.net_price(10) << endl;

    return 0;
}
