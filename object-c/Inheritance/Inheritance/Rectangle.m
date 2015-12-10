//
//  Rectangle.m
//  Inheritance
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Rectangle.h"
#import "stdio.h"

@implementation Rectangle

-(Rectangle*) initWithWidth:(int)w height:(int)h
{
    self = [super init];
    if (self) {
        [self setWidth:w height:h];
    }
    return self;
}
-(void) setWidth:(int)w
{
    width = w;
}
-(void) setHeight:(int)h
{
    height = h;
}
-(void) setWidth:(int)w height:(int) h
{
    width = w;
    height = h;
}
-(int) width
{
    return width;
}
-(int) height
{
    return height;
}
-(void) print
{
    printf("width = %i, height = %i",width,height);
}

@end