//
//  Cup.m
//  ExceptionTest
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/NSString.h>
#import "Cup.h"
#import "CupOverflowException.h"
#import "CupWarningException.h"
@implementation Cup
-(id) init
{
    self = [super init];
    if (self) {
        [self setLevel:0];
    }
    return self;
}
-(int) level
{
    return level;
}
-(void) setLevel:(int)l
{
    level = l;
    if (level > 100) {
        // throw over flow
        NSException *e = [NSException
                          exceptionWithName:@"CupOverflowException"
                          reason:@"The level is above 100"
                          userInfo:nil];
        @throw e;
    }
    else if (level >= 50)
    {
        // throw warning
        NSException *e = [NSException
                          exceptionWithName:@"CupUnderflowException"
                          reason:@"The level is below 0"
                          userInfo:nil];
        @throw e;
    }
}

-(void) fill
{
    [self setLevel:level + 10];
}

-(void) empty
{
    [self setLevel:level -10];
}
-(void) print
{
    printf("Cup level is:%i\n",level);
}
@end
