//
//  Rectangle.h
//  Inheritance
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/NSObject.h>
@interface Rectangle:NSObject
{
    int width;
    int height;
}
-(Rectangle*) initWithWidth:(int) w height:(int) h;
-(void) setWidth:(int) w;
-(void) setHeight:(int) h;
-(void) setWidth:(int) w height:(int) h;
-(int) width;
-(int) height;
-(void) print;
@end