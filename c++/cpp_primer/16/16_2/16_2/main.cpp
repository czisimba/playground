//
//  main.cpp
//  16_2
//
//  Created by nichola on 15/12/3.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T1,typename T2>
void print_out(T1 &s, const T2 &v) {
    s << v;
}

int main(int argc, const char * argv[]) {
    string dest;
    ostringstream oss(dest);
    print_out(cout, 1);
    print_out(cout, 1.1);
    print_out(cout, "hello");
    print_out(oss, "world");
    cout << oss.str() << endl;
    
    return 0;
}
