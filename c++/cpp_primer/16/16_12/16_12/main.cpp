//
//  main.cpp
//  16_12
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace::std;

//template <typename T> typename T::size_type find_frequent(T &beg,T &end) {
template <typename T,typename U> size_t find_frequent(T beg,T end,U t) {
    map<U,size_t> cnt;
    for (;beg != end; ++beg) {
        ++cnt[*beg];
    }
    size_t max_cnt = 0;
    for (typename map<U, size_t>::iterator iter = cnt.begin(); iter != cnt.end(); ++iter) {
        if ((*iter).second > max_cnt)
            max_cnt = (*iter).second;
    }
    
    return max_cnt;
}

template <typename T> T fcn(T p) {
    return p;
}

int main(int argc, const char * argv[]) {
    string s[] = {"cz","cz", "yx", "cz", "yx", "yx", "yx"};
    vector<string> sv(s, s + 7);
    size_t st = find_frequent(sv.begin(), sv.end(), sv[0]);
    cout << st << endl;
    
    int *p = new int(10);
    int *v = fcn(p);
    cout << *v << endl;
    return 0;
}
