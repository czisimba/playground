//
//  main.cpp
//  boost_thread
//
//  Created by nichola on 15/12/14.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <boost/thread/thread.hpp>

void hello()
{
    std::cout << "Hello world, I'm a thread!" << std::endl;
}

int main()
{
    boost::thread thrd(&hello);
    thrd.join();
    return 0;
}