//
//  main.cpp
//  16_14
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_fcn(T &c) {
    for (typename T::iterator iter = c.begin(); iter != c.end(); ++iter) {
        cout << *iter << endl;
    }
}
int main(int argc, const char * argv[]) {
    int ia[] = {1,2,3,4,5,6,7};
    vector<int> iv(ia, ia + 7);
    print_fcn(iv);
    
    return 0;
}
