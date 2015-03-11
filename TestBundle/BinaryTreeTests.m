//
//  BinaryTreeTests.m
//  PointMeDown
//
//  Created by Martin Nash on 3/11/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "BinaryTree.h"
#import <string.h>

@interface BinaryTreeTests : XCTestCase

@end

@implementation BinaryTreeTests

- (void)testCreation {
    BinaryTree *root = BinaryTreeCreate(3);
    XCTAssert(root != NULL);
    XCTAssert(root->value == 3);
    XCTAssert(root->left == NULL);
    XCTAssert(root->right == NULL);
}

- (void)testAppending {
    BinaryTree *root = BinaryTreeCreate(10);
    BinaryTreeAppend(&root, 0);
    BinaryTreeAppend(&root, 33);

    XCTAssert(root != NULL);
    XCTAssert(root->value == 10);
    XCTAssert(root->left != NULL);
    XCTAssert(root->right != NULL);

    XCTAssert(root->left->value == 0);
    XCTAssert(root->right->value == 33);
    
    
    BinaryTree *nilRoot = NULL;
    BinaryTreeAppend(&nilRoot, 30);
    XCTAssert(nilRoot != NULL);
    XCTAssert(nilRoot->value == 30);
}

- (void)testCounting {
    BinaryTree *root = BinaryTreeCreate(10);
    XCTAssert(BinaryTreeCount(root) == 1);

    BinaryTreeAppend(&root, 0);
    XCTAssert(BinaryTreeCount(root) == 2);

    BinaryTreeAppend(&root, 33);
    XCTAssert(BinaryTreeCount(root) == 3);
}

- (void)testContains {

    BinaryTree *root = BinaryTreeCreate(10);
    BinaryTreeAppend(&root, 0);
    BinaryTreeAppend(&root, 33);

    XCTAssert(BinaryTreeContainsValue(root, -99) == 0);
    XCTAssert(BinaryTreeContainsValue(root, 10) == 1);
    XCTAssert(BinaryTreeContainsValue(root, 0) == 1);
    XCTAssert(BinaryTreeContainsValue(root, 33) == 1);
}

- (void)testLCRString {
    BinaryTree *root = BinaryTreeCreate(10);
    
    char * firstResult = BinaryTreeLCRString(root);
    XCTAssert(strcmp(firstResult, "10") == 0);

    
    BinaryTreeAppend(&root, 0);
    char * secondResult = BinaryTreeLCRString(root);
    XCTAssert(strcmp(secondResult, "0, 10") == 0);
    
    
    BinaryTreeAppend(&root, 33);
    char * thirdResult = BinaryTreeLCRString(root);
    XCTAssert(strcmp(thirdResult, "0, 10, 33") == 0);

}


@end
