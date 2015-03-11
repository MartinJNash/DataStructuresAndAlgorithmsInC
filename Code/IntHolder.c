

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


