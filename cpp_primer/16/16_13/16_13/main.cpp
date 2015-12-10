//
//  main.cpp
//  16_13
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_container(T &c) {
    for (typename T::size_type idx = 0; idx < c.size(); ++idx) {
        cout << c[idx] << endl;
    }
}
int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6,7};
    vector<int> iv(arr, arr + 7);
    
    print_container(iv);
    
    return 0;
}
