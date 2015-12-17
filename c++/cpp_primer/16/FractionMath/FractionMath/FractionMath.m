//
//  FractionMath.m
//  FractionMath
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FractionMath.h"
@implementation Fraction (Math)
-(Fraction*) add: (Fraction*) f {
    
    return [[Fraction alloc]
            initWithNumerator: numerator * [f denominator] + denominator * [f numerator]
            ominator: denominator * [f denominator]];
    
    return self;
}
-(Fraction*) mul: (Fraction*) f {
    return [[Fraction alloc] initWithNumerator: numerator * [f numerator]
                                   denominator: denominator * [f denominator]];
}
-(Fraction*) div: (Fraction*) f {
    return [[Fraction alloc] initWithNumerator: numerator * [f denominator]
                                   denominator: denominator * [f numerator]];
}
-(Fraction*) sub: (Fraction*) f {
    return [[Fraction alloc] initWithNumerator: numerator * [f denominator] -
            denominator * [f numerator] denominator: denominator * [f denominator]];
}
@end