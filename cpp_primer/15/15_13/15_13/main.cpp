//
//  main.cpp
//  15_13
//
//  Created by nichola on 15/11/30.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace std;

class ConsreteBase {
public:
    static size_t p_size() {
        return 0;
    }
    static int ival;
protected:
    static size_t size;
};
int ConsreteBase::ival = 1;

class C1:public ConsreteBase {
public:
    void f(const C1 &c1) {
        cout << ConsreteBase::p_size() << endl;
        cout << C1::p_size() << endl;
        cout << ConsreteBase::ival << endl;
        cout << C1::ival << endl;
        cout << ival << endl;
    }
    
};

int main(int argc, const char * argv[]) {
    ConsreteBase c1;
    
    cout << c1.p_size() << endl;
    cout << c1.ival << endl;

    return 0;
}
