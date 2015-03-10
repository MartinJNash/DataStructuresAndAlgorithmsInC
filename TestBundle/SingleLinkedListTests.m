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
#import <string.h>

@interface SingleLinkedListTests : XCTestCase
{
    SingleLinkedList *ll;
}
@end

@implementation SingleLinkedListTests

-(void)setUp {
    
    [super setUp];
    
    ll = SingleLinkedListAppend(ll, 0);
    ll = SingleLinkedListAppend(ll, 1);
    ll = SingleLinkedListAppend(ll, 2);
    ll = SingleLinkedListAppend(ll, 3);

}

- (void)testCreation {

    int zero = 0;
    SingleLinkedList *zeroList = SingleLinkedListCreate(zero);
    XCTAssert(SingleLinkedListGetValueAtIndex(zeroList, 0) == zero);
    
    int large = 1234;
    SingleLinkedList *maxList = SingleLinkedListCreate(large);
    XCTAssert(SingleLinkedListGetValueAtIndex(maxList, 0) == large);
    
}

- (void)testAppending {
    
    SingleLinkedList *localList = NULL;
    localList = SingleLinkedListAppend(localList, 1);
    localList = SingleLinkedListAppend(localList, 2);

    XCTAssert(localList->next != NULL);
    XCTAssert(localList->value == 1);
    XCTAssert(localList->next->value == 2);
    
}

- (void)testContains {
    XCTAssert(SingleLinkedListContains(ll, -1) == 0);
    XCTAssert(SingleLinkedListContains(ll, 0) == 1);
    XCTAssert(SingleLinkedListContains(ll, 3) == 1);
    XCTAssert(SingleLinkedListContains(ll, 4) == 0);
   
}

- (void)testValueAtIndex {
    XCTAssert(SingleLinkedListGetValueAtIndex(ll, 0) == 0);
    XCTAssert(SingleLinkedListGetValueAtIndex(ll, 1) == 1);
    XCTAssert(SingleLinkedListGetValueAtIndex(ll, 2) == 2);
    XCTAssert(SingleLinkedListGetValueAtIndex(ll, 3) == 3);
}

- (void)testToString {
    char * expected = "0, 1, 2, 3";
    char * actual   = SingleLinkedListToString(ll);
    int result = strcmp(expected, actual);
    XCTAssert(result == 0); // strcmp returns zero for equal strings
}

- (void)testCount {
    XCTAssert(SingleLinkedListGetCount(ll) == 4);
    
    SingleLinkedList *empty = NULL;
    XCTAssert(SingleLinkedListGetCount(empty) == 0);
    
    SingleLinkedList *one = SingleLinkedListCreate(1);
    XCTAssert(SingleLinkedListGetCount(one) == 1);

}


@end
