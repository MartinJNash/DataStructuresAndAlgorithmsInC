//
//  Stack.c
//  DataStructuresAndAlgorithmsInC
//
//  Created by Martin Nash on 3/15/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#include "Stack.h"

void StackPush(Stack **s, int num) {

    // push first
    Stack *newOne = SingleLinkedListCreate(num);
    newOne->next = *s;
    *s = newOne;
}


int StackPop(Stack **s) {
    
    // pop first
    int val = (*s)->value;
    *s = (*s)->next;
    return val;
}

int StackCount(Stack *s) {
    if (s == NULL) {
        return 0;
    }
    
    return 1 + StackCount(s->next);
}
