//
//  Fraction.m
//  interface_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction.h"
#import <stdio.h>

@implementation Fraction
-(Fraction *) initWithNumerator:(int)n denominator:(int) d
{
    self = [super init];
    if (self) {
        [self setNUmberator:n andDenominator:d];
    }
    return self;
}
-(void) print
{
    printf("%i/%i",numerator, denominator);
}

-(void) setNUmberator:(int)n
{
    numerator = n;
}

-(void) setNUmberator:(int)n andDenominator:(int)d
{
    numerator = n;
    denominator = d;
}

-(void) SetDenominator:(int)d
{
    denominator = d;
}

-(int) denominator
{
    return denominator;
}

-(int) numerator
{
    return numerator;
}
@end
