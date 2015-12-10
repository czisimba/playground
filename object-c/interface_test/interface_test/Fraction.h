//
//  Fraction.h
//  interface_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/NSObject.h>

@interface Fraction : NSObject
{
    int numerator;
    int denominator;
}
-(Fraction *) initWithNumerator:(int)n denominator:(int) d;
-(void) print;
-(void) setNUmberator:(int) n;
-(void) setNUmberator:(int) n andDenominator:(int) d;
-(void) SetDenominator:(int) d;
-(int) numerator;
-(int) denominator;
@end

