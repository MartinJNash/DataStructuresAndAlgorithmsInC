//
//  TestBundle.m
//  TestBundle
//
//  Created by Martin Nash on 3/10/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "SingleLinkedList.h"

@interface SingleLinkedListTests : XCTestCase
@end

@implementation SingleLinkedListTests


- (void)testCreation {

    int zero = 0;
    SingleLinkedList *zeroList = SingleLinkedListCreate(zero);
    XCTAssert(SingleLinkedListGetValue(zeroList) == zero);
    
    int large = 1234;
    SingleLinkedList *maxList = SingleLinkedListCreate(large);
    XCTAssert(SingleLinkedListGetValue(maxList) == large);
    
}

- (void)testAppending {
    
    SingleLinkedList *ll = SingleLinkedListCreate(0);
    SingleLinkedListAppend(ll, 1);

    XCTAssert(ll->next != NULL);
    XCTAssert(ll->value == 0);
    XCTAssert(ll->next->value == 1);
    
}


@end
