//
//  main.cpp
//  16_24
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename T> T compare(const T& v1,const T& v2) {
    return v1 > v2 ? v1 : v2;
}

int main(int argc, const char * argv[]) {
    short x = 3;
    int y = 4;
    compare(static_cast<int>(x),y);
    compare(x, static_cast<short>(y));
    compare<int>(x, y);
    
    return 0;
}
