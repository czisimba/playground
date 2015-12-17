//
//  main.cpp
//  template_test
//
//  Created by nichola on 15/12/3.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace std;
template <typename T>
int compare(T &v1,T &v2) {
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int v1 = 4, v2 = 3;
    int ret = 0;
    ret = compare(v1, v2);
    cout << ret << endl;
    return 0;
}
