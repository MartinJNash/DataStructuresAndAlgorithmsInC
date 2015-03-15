//
//  StackTests.m
//  DataStructuresAndAlgorithmsInC
//
//  Created by Martin Nash on 3/15/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "Stack.h"

@interface StackTests : XCTestCase
@end

@implementation StackTests

- (void)testPush {
    Stack *t = NULL;
    StackPush(&t, 3);
    
    XCTAssert(t->value == 3);
    XCTAssert(t->next == NULL);
    
    StackPush(&t, 4);
    XCTAssert(t->value == 4);
    XCTAssert(t->next->value == 3);
    

    
}

- (void)testPop {
    Stack *t = NULL;
    StackPush(&t, 3);
    StackPush(&t, 4);
    
    int top = StackPop(&t);
    XCTAssert(top == 4);

    int bottom = StackPop(&t);
    XCTAssert(bottom == 3);
    
    XCTAssert(t == NULL);
    
}

- (void)testCount {
    Stack *t = NULL;
    XCTAssert(StackCount(t) == 0);

    StackPush(&t, 3);
    XCTAssert(StackCount(t) == 1);

    StackPush(&t, 4);
    XCTAssert(StackCount(t) == 2);
}


@end
