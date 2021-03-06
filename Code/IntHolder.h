

#ifndef __PointMeDown__IntHolder__
#define __PointMeDown__IntHolder__

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} IntHolder;


// last word is new type, before that is old type
typedef IntHolder* IntHolderRef;


IntHolderRef IntHolderCreate(int value);
void IntHolderFree(IntHolderRef ref);
void IntHolderDouble(IntHolderRef ih);


#endif /* defined(__PointMeDown__IntHolder__) */
