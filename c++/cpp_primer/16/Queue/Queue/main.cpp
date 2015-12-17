//
//  main.cpp
//  Queue
//
//  Created by nichola on 15/12/6.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    int ia[] = {1,2,3,4,5,6,7};
    std::vector<int> iv(ia, ia+7);
    Queue<int> qi;
    Queue<int> qi1;
    short s = 42;
    int i = 38;
    qi.push(s);
    qi.push(i);
    qi.assign(iv.begin(), iv.end());
    //std::cin >> qi;
    std::cout << qi << std::endl;
    qi.pop();
    qi1 = qi;
    
    return 0;
}
