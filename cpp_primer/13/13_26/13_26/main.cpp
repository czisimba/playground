//
//  main.cpp
//  13_26
//
//  Created by nichola on 15/11/27.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace::std;

class Hash_ptr {
public:
    Hash_ptr(int* const p):ptr(p) {
    }
    Hash_ptr(const Hash_ptr &rhp):ptr(new int(*rhp.ptr)) {
    }
    ~Hash_ptr() {
        delete ptr;
    }
    
    int *ptr;
private:
};
int main(int argc, const char * argv[]) {
    Hash_ptr p0(new int(100));
    Hash_ptr p1(p0);
    Hash_ptr p2(p0);
    
    *p0.ptr = 0;
    *p1.ptr = 1;
    *p2.ptr = 2;
    cout << *p0.ptr << endl;
    cout << *p1.ptr << endl;
    cout << *p2.ptr << endl;
    
    return 0;
}
