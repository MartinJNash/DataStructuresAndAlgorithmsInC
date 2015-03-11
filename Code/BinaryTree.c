//
//  BinaryTree.c
//  PointMeDown
//
//  Created by Martin Nash on 3/11/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//


#include "BinaryTree.h"
#include <stdlib.h>
#include <string.h>

BinaryTree * BinaryTreeCreate(int val) {
    BinaryTree * bt = malloc(sizeof(BinaryTree));
    bt->value = val;
    bt->right = NULL;
    bt->left = NULL;
    return bt;
}

void BinaryTreeAppend(BinaryTree **root, int val) {
    
    if (*root == NULL) {
        *root = BinaryTreeCreate(val);
    } else if (val <= (*root)->value) {
        BinaryTreeAppend(&(*root)->left, val);
    } else {
        BinaryTreeAppend(&(*root)->right, val);
    }
    
}

int BinaryTreeCount(BinaryTree *root) {

    if (root == NULL) {
        return 0;
    }
    
    return 1 + BinaryTreeCount(root->left) + BinaryTreeCount(root->right);
}

int BinaryTreeContainsValue(BinaryTree *root, int val) {
    
    if (root == NULL) {
        return 0;
    } if (root->value == val) {
        return 1;
    } if (val <= root->value) {
        return BinaryTreeContainsValue(root->left, val);
    } else {
        return BinaryTreeContainsValue(root->right, val);
    }
}

char * BinaryTreeLCRString(BinaryTree *root) {
    char * res = malloc(sizeof(char) * 8000);
    BinaryTreeLCRStringMutating(root, &res);
    return res;
}

void BinaryTreeLCRStringMutating(BinaryTree *root, char ** string) {

    // append left
    if (root->left != NULL) {
        BinaryTreeLCRStringMutating(root->left, string);
        strcat(*string, ", ");
    }
    
    char curr[233];
    sprintf(curr, "%i", root->value);
    strcat(*string, curr);
    
    // append right
    if (root->right != NULL) {
        strcat(*string, ", ");
        BinaryTreeLCRStringMutating(root->right, string);
    }
    
    
    
}

