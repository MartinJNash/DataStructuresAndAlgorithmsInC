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


// Leaks memory
char * BinaryTreeLCRString(BinaryTree *root) {
    
    char * holder = malloc(sizeof(char) * 9999);
    
    // append left
    if (root->left != NULL) {
        char * lString = BinaryTreeLCRString(root->left);
        strcat(holder, lString);
        strcat(holder, ", ");
    }
    
    char curr[233];
    sprintf(curr, "%i", root->value);
    strcat(holder, curr);
    
    // append right
    if (root->right != NULL) {
        strcat(holder, ", ");
        char * rString = BinaryTreeLCRString(root->right);
        strcat(holder, rString);
    }
    
    
    return holder;
    
}

