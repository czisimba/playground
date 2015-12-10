//
//  main.cpp
//  template_compile
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include "sum.h"
using namespace::std;

int main(int argc, const char * argv[]) {
    int v1(3),v2(4),sum_v;
    sum_v = sum_aa(v1, v2);
    cout << sum_v << endl;
    
    return 0;
}
