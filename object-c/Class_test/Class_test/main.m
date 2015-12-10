//
//  main.m
//  Class_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClassA.h"

int main(int argc, const char * argv[]) {
    ClassA *c1 = [[ClassA alloc] init];
    ClassA *c2 = [[ClassA alloc] init];
    
    // print count
    printf("ClassA count:%i\n", [ClassA initCount]);
    
    ClassA *c3 = [[ClassA alloc] init];
    
    // print count again
    printf("ClassA count:%i\n", [ClassA initCount]);
    return 0;
}
