//
//  main.cpp
//  16_9
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

using namespace::std;

template<typename I, typename T> I find_T(I beg,I end,const T value) {
    for (; beg != end; ++beg) {
        if (*beg == value) {
            return beg;
        }
    }
    return end;
}

int main(int argc, const char * argv[]) {
    vector<int> iv;
    list<string> sl;
    iv.push_back(1);
    iv.push_back(2);
    sl.push_back("cz");
    sl.push_back("yx");
    vector<int>::iterator iter = find_T(iv.begin(),iv.end(),2);
    list<string>::iterator iter1 = find_T(sl.begin(), sl.end(), "cz");
    
    cout << *iter << endl;
    cout << *iter1 << endl;
    
    return 0;
}
