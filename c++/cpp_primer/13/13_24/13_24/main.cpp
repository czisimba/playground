//
//  main.cpp
//  13_24
//
//  Created by nichola on 15/11/27.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace::std;

class U_ptr {
public:
    int *ip;
    size_t use;
    U_ptr(int* const p):ip(p),use(1) {
    }
    ~U_ptr() {
        cout << "~U_ptr" << endl;
        delete ip;
    }
};
class Hash_ptr {
public:
    Hash_ptr(int* const p):ptr(new U_ptr(p)),ival(0) {
        cout << "user_count:" << ptr->use << endl;
    }
    Hash_ptr(const Hash_ptr &rhp):ptr(rhp.ptr),ival(rhp.ival) {
        ++rhp.ptr->use;
        cout << "user_count:" << ptr->use << endl;
    }
    ~Hash_ptr() {
        cout << "user_count:" << ptr->use << endl;
        if (--ptr->use == 0) {
            delete ptr;
        }
    }
    
private:
    U_ptr *ptr;
    int ival;
};
int main(int argc, const char * argv[]) {
    int *ip = new int(100);
    Hash_ptr p0(ip);
    Hash_ptr p1(p0);
    Hash_ptr p2(p0);
    
    return 0;
}
