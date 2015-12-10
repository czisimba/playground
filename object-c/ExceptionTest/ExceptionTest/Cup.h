//
//  Cup.h
//  ExceptionTest
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/NSObject.h>

@interface Cup : NSObject
{
    int level;
}
-(int) level;
-(void) setLevel:(int) l;
-(void) fill;
-(void) empty;
-(void) print;
@end
