//
//  main.cpp
//  15_8
//
//  Created by nichola on 15/11/30.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>

using namespace::std;

class base {
public:
    base(const string &s):basename(s) {
    }
    virtual void print() {
        cout << basename << " " << endl;
    }
private:
    string basename;
};

class derieved:public base {
public:
    derieved(const string &s, const int m):base(s),mem(m) {
    }
    void print() {
        base::print();
        cout << mem << " " << endl;
    }
private:
    int mem;
};

int main(int argc, const char * argv[]) {
    derieved d("cz", 17);
    d.print();
    return 0;
}
