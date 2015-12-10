//
//  ClassA.m
//  Class_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClassA.h"

@implementation ClassA

-(id) init
{
    self = [super init];
    count++;
    return self;
}

+(int) initCount
{
    return count;
}

+(void) initialize
{
    count = 0;
}
@end

