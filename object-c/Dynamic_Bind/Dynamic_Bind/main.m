//
//  main.m
//  Dynamic_Bind
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Square.h"
#import "Rectangle.h"
#import <stdio.h>

int main(int argc, const char * argv[]) {
    Rectangle *rec = [[Rectangle alloc] initWithWidth:10 height:20];
    Squre *sq = [[Squre alloc] initWithSize:15];
    // isMemberOfClass
    // true
    if ([sq isMemberOfClass:[Squre class]] == YES) {
        printf("Squre is a member of squre class\n");
    }
    // false
    if ([sq isMemberOfClass:[Rectangle class]] == YES) {
        printf("squre is a memeber of rectangle class\n");
    }
    
    // false
    if ([sq isMemberOfClass:[NSObject class]] == YES) {
        printf("Squre is a member of object class\n");
    }
    // isKindOfClass
    // true
    if ([sq isKindOfClass:[Squre class]]) {
        printf("Squre is a kind of squre class\n");
    }
    // true
    if ([sq isKindOfClass:[Rectangle class]]) {
        printf( "square is a kind of rectangle class\n" );
    }
    // true
    if ([sq isKindOfClass:[NSObject class]] == YES) {
        printf( "square is a kind of object class\n" );
    }
    // respondsToSelector
    // true
    if ([sq respondsToSelector:@selector(setSize:)] == YES) {
        printf( "square responds to setSize: 方法\n" );
    }
    // false
    if ([sq respondsToSelector:@selector(nonExistant)] == YES) {
        printf("square respondstononExistant 方法\n");
    }
    // true
    if ([Squre respondsToSelector:@selector(alloc)] == YES) {
        printf( "square class responds to alloc 方法\n" );
    }
    // instancesRespondToSelector
    // false
    if ([Rectangle instancesRespondToSelector:@selector(setSize:)] == YES) {
        printf( "rectangle instance responds to setSize: 方法\n" );
    }
    
    // true
    if ([Squre instancesRespondToSelector:@selector(setSize:)] == YES) {
        printf( "square instance responds to setSize: 方法\n" );
    }
    
    return 0;
}
