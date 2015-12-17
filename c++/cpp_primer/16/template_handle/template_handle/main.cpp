//
//  main.cpp
//  template_handle
//
//  Created by nichola on 15/12/8.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include "template_handle.h"

int main(int argc, const char * argv[]) {
    int *iv = new int(42);
    Handle<int> hp(iv);
    Handle<int> hp1 = hp;
    std::cout << *hp << "\t" << *hp1 << std::endl;
    
    return 0;
}
