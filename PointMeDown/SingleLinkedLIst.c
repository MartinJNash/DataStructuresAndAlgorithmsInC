
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

