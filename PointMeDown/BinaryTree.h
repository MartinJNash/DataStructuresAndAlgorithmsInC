//
//  BinaryTree.h
//  PointMeDown
//
//  Created by Martin Nash on 3/11/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#ifndef __PointMeDown__BinaryTree__
#define __PointMeDown__BinaryTree__

#include <stdio.h>

typedef struct BinaryTree {
    int value;
    struct BinaryTree * left;
    struct BinaryTree * right;
} BinaryTree;

BinaryTree * BinaryTreeCreate(int val);
void BinaryTreeAppend(BinaryTree **root, int val) ;
int BinaryTreeContainsValue(BinaryTree *root, int val);
int BinaryTreeCount(BinaryTree *root);

char * BinaryTreeLCRString(BinaryTree *root);

#endif /* defined(__PointMeDown__BinaryTree__) */
