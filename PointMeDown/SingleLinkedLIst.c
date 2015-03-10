//
//  SingleLinkedLIst.c
//  PointMeDown
//
//  Created by Martin Nash on 3/10/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#include "SingleLinkedLIst.h"
#include <stdlib.h>

SingleLinkedList * SingleLinkedListCreate(int value) {
    SingleLinkedList * ll = malloc(sizeof(SingleLinkedList));
    ll->value = value;
    return ll;
}

void SingleLinkedListFree(SingleLinkedList * ll) {
    free(ll);
}

SingleLinkedList * SingleLinkedListAppend(SingleLinkedList * root, int value) {

    // if null, make new list
    if (root == NULL) {
        return SingleLinkedListCreate(value);
    }

    // if not null, try to make on next
    root->next = SingleLinkedListAppend(root->next, value);
    return root;
}

void SingleLinkedListPrint(SingleLinkedList * ll) {
    
    // iterates, moving current to current.next each time until null
    for (SingleLinkedList *current = ll; current != NULL; current = current->next) {
        printf("%i, ", current->value);
    }
    
//    Equivalent
//    
//    SingleLinkedList * current = ll;
//    while (current != NULL) {
//        current = current->next;
//    }
    
}

int SingleLinkedListContains(SingleLinkedList * ll, int val) {
    
    if (ll == NULL) {
        return 0;
    } else if (ll->value == val) {
        return 1;
    }
    
    return SingleLinkedListContains(ll->next, val);
    
}

void SingleLinkedListDeleteAtIndex(SingleLinkedList **head, int index) {

    if (index < 0) {
        return;
    }
    
    if (*head == NULL) {
        return;
    }
    
    if (index == 0) {
        SingleLinkedList *oldHead = *head;
        (*head) = (*head)->next;
        free(oldHead);
    }
    
    SingleLinkedListDeleteAtIndex(&(*head)->next, index-1);
    
}


