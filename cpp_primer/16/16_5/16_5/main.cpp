//
//  main.cpp
//  16_5
//
//  Created by nichola on 15/12/3.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>

using namespace::std;

template <class Type> class V {
public:
    Type v1;
    Type v2;
    Type get_bigger() {
        return v1 >= v2 ? v1 : v2;
    }
};

int main(int argc, const char * argv[]) {
    V<int> vs;
    vs.v1 = 4;
    vs.v2 = 3;
    cout << vs.get_bigger() << endl;
    
    return 0;
}
