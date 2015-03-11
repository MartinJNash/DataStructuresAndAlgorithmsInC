

#ifndef __PointMeDown__SingleLinkedLIst__
#define __PointMeDown__SingleLinkedLIst__

#include <stdio.h>

typedef struct SingleLinkedList {
    int value;
    struct SingleLinkedList * next;
} SingleLinkedList;

SingleLinkedList * SingleLinkedListCreate(int value);
SingleLinkedList * SingleLinkedListAppend(SingleLinkedList * root, int value);

int SingleLinkedListGetCount(SingleLinkedList *ll);
int SingleLinkedListContains(SingleLinkedList * ll, int val);
int SingleLinkedListGetValueAtIndex(SingleLinkedList * ll, int index);

void SingleLinkedListFree(SingleLinkedList * ll);
void SingleLinkedListDeleteAtIndex(SingleLinkedList **head, int index);
void SingleLinkedListPrint(SingleLinkedList * ll);

char * SingleLinkedListToString(SingleLinkedList *ll);


#endif /* defined(__PointMeDown__SingleLinkedLIst__) */
