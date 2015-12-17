//
//  main.cpp
//  16_22
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace::std;

template <typename T> void fcn(T v) {
    cout << *v << endl;
}

int main(int argc, const char * argv[]) {
    int *p = new int(3);
    int v = 3;
    fcn(v);
    return 0;
}
