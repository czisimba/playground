//
//  main.cpp
//  template_special
//
//  Created by nichola on 15/12/9.
//  Copyright © 2015年 nichola. All rights reserved.
//

#include <iostream>
#include <string.h>

template <typename T>
int compare(const T &v1,const T& v2) {
    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}
template <>
int compare<const char*>(const char* const &s1, const char* const &s2) {
    return strcmp(s1, s2);
}
template <>
int compare<int>(const int &v1, const int &v2) {
    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}

int compare(const int& v1,const int& v2) {
    if (v1 < v2)
        return 1;
    if (v1 > v2)
        return -1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int v1 = 1,v2 = 2,v3;
    v3 = compare(v1, v2);
    std::cout << v3 << std::endl;
    
    return 0;
}
