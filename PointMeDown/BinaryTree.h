
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
void BinaryTreeLCRStringMutating(BinaryTree *root, char ** string);

#endif /* defined(__PointMeDown__BinaryTree__) */
