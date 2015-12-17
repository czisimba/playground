//
//  main.cpp
//  template_part_special
//
//  Created by nichola on 15/12/9.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string>

template <class T1, class T2>
class some_tempalte {
public:
    int v1;
};

template <class T1>
class some_tempalte<T1,int> {
public:
    int v2;
};

int main(int argc, const char * argv[]) {
    some_tempalte<std::string, std::string> st1;
    some_tempalte<int, int> st2;
    st1.v1 = 1;
    st2.v2 = 2;
    std::cout << st1.v1 << std::endl;
    //std::cout << st2.v1 << std::endl; // seems like special tempalte is new tempalte
    std::cout << st2.v2 << std::endl;
    
    return 0;
}
