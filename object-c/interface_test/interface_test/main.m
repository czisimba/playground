//
//  main.m
//  interface_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Fraction.h"


int main(int argc, const char * argv[]) {
    // create a new instance
    Fraction *frac = [[Fraction alloc] init];
    Fraction *frac2 = [[Fraction alloc] init];
    Fraction *frac3 = [[Fraction alloc] initWithNumerator:3 denominator:10];
    // set the values
    [frac setNUmberator:1];
    [frac SetDenominator:3];
    
    [frac2 setNUmberator:1 andDenominator:5];
    
    
    // print it
    printf("The fraction is:");
    [frac print];
    printf("\n");
    // free memory
    //[frac ];
    
    printf("The fraction is:");
    [frac2 print];
    printf("\n");
    
    printf("The fraction is:");
    [frac3 print];
    printf("\n");
    
    return 0;
}
