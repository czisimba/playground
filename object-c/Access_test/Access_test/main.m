//
//  main.m
//  Access_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Access.h"

int main(int argc, const char * argv[]) {
    Access *a = [[Access alloc] init];
    
    // works
    a->publicVar = 5;
    printf("public var:%i\n",a->publicVar);
    
    // doesn't compile
    //a->printvar = 10;
    //printf("private var :%i\n", a->pritVar);
    //[a release];
    
    return 0;
}
