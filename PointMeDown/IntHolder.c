//
//  IntHolder.c
//  PointMeDown
//
//  Created by Martin Nash on 3/10/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#include "IntHolder.h"


IntHolderRef IntHolderCreate(int value) {
    IntHolder * ih = malloc(sizeof(IntHolder));
    ih->value = value;
    return ih;
}

void IntHolderFree(IntHolderRef ref) {
    free(ref);
}

void IntHolderDouble(IntHolderRef ih) {
    ih->value *= 2;
}


