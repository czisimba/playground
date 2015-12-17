//
//  main.cpp
//  16_15
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;

template <typename  T,size_t N> size_t get_arr_len(T (&parm)[N]) {
    cout << "arr len is:" << N << endl;
    return N;
}
int main(int argc, const char * argv[]) {
    int ia[] = {1,2,3,4,5};
    get_arr_len(ia);
    
    vector<int>::iterator::value_type i = 3;
    cout << i << endl;
    return 0;
}
