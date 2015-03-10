//
//  main.c
//  PointMeDown
//
//  Created by Martin Nash on 3/10/15.
//  Copyright (c) 2015 Martin Nash. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "IntHolder.h"
#include "SingleLinkedLIst.h"

void blankLines(int num) {
    while (num > 0) {
        printf("\n");
        num--;
    }
}

int main(int argc, const char * argv[]) {

    SingleLinkedList * ll = SingleLinkedListCreate(0);
    SingleLinkedListAppend(ll, 1);
    SingleLinkedListDeleteAtIndex(&ll, -1);
    SingleLinkedListPrint(ll);
    
    
    blankLines(3);
    return 0;
}
