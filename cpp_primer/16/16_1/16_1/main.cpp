//
//  main.cpp
//  16_1
//
//  Created by nichola on 15/12/3.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T>
T GetAbsoluteValue(const T &v)
{
    if (v >= 0)
        return v;
    return -v;
}
int main(int argc, const char * argv[]) {
    cout << GetAbsoluteValue(1) << endl;
    cout << GetAbsoluteValue(-1) << endl;
    cout << GetAbsoluteValue(0.1) << endl;
    cout << GetAbsoluteValue(-0.1) << endl;
    cout << GetAbsoluteValue(0x11) << endl;
    cout << GetAbsoluteValue(-0x11) << endl;
    
    return 0;
}
