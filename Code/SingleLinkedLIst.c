
#include "SingleLinkedLIst.h"
#include <stdlib.h>
#include <string.h>



SingleLinkedList * SingleLinkedListCreate(int value) {
    SingleLinkedList * ll = malloc(sizeof(SingleLinkedList));
    ll->value = value;
    ll->next = NULL;
    return ll;
}

SingleLinkedList * SingleLinkedListAppend(SingleLinkedList * root, int value) {

    // if null, make new list
    if (root == NULL) {
        root = SingleLinkedListCreate(value);

    } else {
        root->next = SingleLinkedListAppend(root->next, value);
    }
    
    return root;
}

char * SingleLinkedListToString(SingleLinkedList * ll) {
    
    int stringLength = 50;
    char * stringer = malloc(sizeof(char) * stringLength);
    
    SingleLinkedList *current = ll;
    while (current != NULL) {

        // create a string for current value
        char local[256];
        sprintf(local, "%i", current->value);
        
        // append comma if next exists
        if (current->next != NULL) {
            strcat(local, ", ");
        }
        
        // append temp string to full string
        strncat(stringer, local, strlen(local));
        
        // go to next
        current = current->next;
    }

    return stringer;
}

int SingleLinkedListContains(SingleLinkedList * ll, int val) {
    
    if (ll == NULL) {
        return 0;
    } else if (ll->value == val) {
        return 1;
    }
    
    return SingleLinkedListContains(ll->next, val);
    
}

int SingleLinkedListGetValueAtIndex(SingleLinkedList * ll, int index) {
    
    if (index == 0) {
        return ll->value;
    }
    
    return SingleLinkedListGetValueAtIndex(ll->next, index - 1);
}

int SingleLinkedListGetCount(SingleLinkedList *ll) {
    
    if (ll == NULL) {
        return 0;
    }
    
    return 1 + SingleLinkedListGetCount(ll->next);
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

void SingleLinkedListFree(SingleLinkedList * ll) {
    free(ll);
}

void SingleLinkedListPrint(SingleLinkedList * ll) {
    
    // iterates, moving current to current.next each time until null
    for (SingleLinkedList *current = ll; current != NULL; current = current->next) {
        printf("%i", current->value);
        if (current->next != NULL) {
            printf(", ");
        }
    }
    
    //    Equivalent
    //
    //    SingleLinkedList * current = ll;
    //    while (current != NULL) {
    //        current = current->next;
    //    }
    
}



// reverses in place
// not recursive
void SingleLinkedListReverseInPlace(SingleLinkedList ** ll) {

    //
    // head = [head, second, t, t, t]
    //
    // reversed = [head]
    // tail = [second, t, t, t]
    //
    
    
    // old reversed = [head], old reversed holds on to reversed
    // head == [ second, t, t, t ]
    // reversed = [second]
    // tail = [t t t]
    // reversed = [second] + old reversed
    
    // old reversed = reversed
    // tail =  head.next
    // reversed = head
    
    
    SingleLinkedList *reversed = NULL;
    SingleLinkedList *head = *ll;

    while (head != NULL) {

        // hold on to old reversed
        SingleLinkedList *oldReversed = reversed;
        
        SingleLinkedList *tail = head->next;
        
        // new reversed gets head
        reversed = head;
        reversed->next = oldReversed;
        head = tail;
        
    }
    
    *ll = reversed;
    
}


// uses append, so creates new structs
// original list untouched
void SingleLinkedListReverseRecursive(SingleLinkedList *ll, SingleLinkedList **accumulation) {
    
    if (ll == NULL) {
        return;
    }

    SingleLinkedListReverseRecursive(ll->next, &(*accumulation));
    *accumulation = SingleLinkedListAppend(*accumulation, ll->value);
    
    
}


// Original, root is modified
// from s/o http://stackoverflow.com/a/1803114/908958
//
SingleLinkedList * SingleLinkedListReverseRecursiveTwo(SingleLinkedList *root, SingleLinkedList *end) {
    
    SingleLinkedList *tail = root->next;
    root->next = end;
    
    if (tail != NULL) {
        return SingleLinkedListReverseRecursiveTwo(tail, root);
    } else {
        return root;
    }
}


// Append a value at a given index
void SingleLinkedListAppendValueAtIndex(SingleLinkedList **list, int val, int index) {
    
    // don't deal with negative indexes
    if (index < 0 ) {
        return;
    }
    
    // if we're at null, and looking to go futher, quit
    // index out of bounds!
    if (*list == NULL && index > 0) {
        return;
    }
    
    // place to add
    if (index == 0) {
        
        SingleLinkedList *new = SingleLinkedListCreate(val);
        SingleLinkedList *old = *list;
        *list = new;
        new->next = old;
        
    }
    
    // move on to next node and try to insert
    SingleLinkedListAppendValueAtIndex(&(*list)->next, val, index-1);
    
}


