

#ifndef __PointMeDown__SingleLinkedLIst__
#define __PointMeDown__SingleLinkedLIst__

#include <stdio.h>

typedef struct SingleLinkedList {
    int value;
    struct SingleLinkedList * next;
} SingleLinkedList;

SingleLinkedList * SingleLinkedListCreate(int value);

int SingleLinkedListGetCount(SingleLinkedList *ll);
int SingleLinkedListContains(SingleLinkedList * ll, int val);
int SingleLinkedListGetValueAtIndex(SingleLinkedList * ll, int index);

void SingleLinkedListFree(SingleLinkedList * ll);
void SingleLinkedListDeleteAtIndex(SingleLinkedList **head, int index);
void SingleLinkedListPrint(SingleLinkedList * ll);
char * SingleLinkedListToString(SingleLinkedList *ll);


#pragma mark - Reversing

void SingleLinkedListReverseInPlace(SingleLinkedList ** ll);
void SingleLinkedListReverseRecursive(SingleLinkedList *ll, SingleLinkedList **accumulation);
SingleLinkedList * SingleLinkedListReverseRecursiveTwo(SingleLinkedList *root, SingleLinkedList *end);



#pragma mark - Insertion / Appending

SingleLinkedList * SingleLinkedListAppend(SingleLinkedList * root, int value);
void SingleLinkedListAppendValueAtIndex(SingleLinkedList **list, int val, int index);
void SingleLinkedListAppendValueAtEnd(SingleLinkedList **list, int val);





#endif /* defined(__PointMeDown__SingleLinkedLIst__) */
