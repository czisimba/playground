//
//  Access.h
//  Access_test
//
//  Created by nichola on 15/12/2.
//  Copyright © 2015年 nichola. All rights reserved.
//

#import <Foundation/NSObject.h>

@interface Access : NSObject
{
@public
    int publicVar;
@private
    int privateVar;
    int privateVar2;
@protected
    int protectedVar;
}
@end
