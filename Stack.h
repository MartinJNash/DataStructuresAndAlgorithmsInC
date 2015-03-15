//
//  Stack.h
//  DataStructuresAndAlgorithmsInC
//
//  Created by Martin Nash on 3/15/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#ifndef __DataStructuresAndAlgorithmsInC__Stack__
#define __DataStructuresAndAlgorithmsInC__Stack__

#include <stdio.h>
#include "SingleLinkedLIst.h"

typedef SingleLinkedList Stack;

void StackPush(Stack **s, int num);
int StackPop(Stack **s);
int StackCount(Stack *s);



#endif /* defined(__DataStructuresAndAlgorithmsInC__Stack__) */
