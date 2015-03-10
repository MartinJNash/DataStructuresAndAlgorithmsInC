//
//  SingleLinkedLIst.h
//  PointMeDown
//
//  Created by Martin Nash on 3/10/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#ifndef __PointMeDown__SingleLinkedLIst__
#define __PointMeDown__SingleLinkedLIst__

#include <stdio.h>

typedef struct SingleLinkedList {
    int value;
    struct SingleLinkedList * next;
} SingleLinkedList;

SingleLinkedList * SingleLinkedListCreate(int value);
SingleLinkedList * SingleLinkedListAppend(SingleLinkedList * parent, int value);
void SingleLinkedListPrint(SingleLinkedList * ll);
int SingleLinkedListContains(SingleLinkedList * ll, int val);

// editing
void SingleLinkedListDeleteAtIndex(SingleLinkedList **head, int index);


#endif /* defined(__PointMeDown__SingleLinkedLIst__) */
