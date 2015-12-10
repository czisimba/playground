//
//  Squre.m
//  Inheritance
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Square.h"

@implementation Squre
-(Squre*) initWithSize:(int)s
{
    self = [super init];
    if (self)
    {
        [self setSize:s];
    }
    return self;
}
-(void) setSize:(int)s
{
    width = s;
    height = s;
}
-(int) size
{
    return width;
}
-(void) setWidth:(int)w
{
    [self setSize:w];
}
-(void) setHeight:(int)h
{
    [self setSize:h];
}
@end
