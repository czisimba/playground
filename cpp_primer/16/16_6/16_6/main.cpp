//
//  main.cpp
//  16_6
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

template <class Type> class List {
public:
    List();// default constructor
    void insert(Type *, const Type &);// insert value in place
    void del(Type *);// delete value
    Type *find(const Type &);// find value
    List &push_back(Type &);
    List &erase(Type &);
    bool empty() const ;// get whether List is empty
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
