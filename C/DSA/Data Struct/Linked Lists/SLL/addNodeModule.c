#include <stdio.h>
#include "list.h"

void addNodeModule(NODE **head) {
    int val;
    char ch;

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &val, &ch)) == 2 && ch == '\n') {

            if(addNode(head, val)) {
                printf("SUCCESS: node added!\n\n");
            } else {
                printf("ERROR: node not added!\n\n");
            }

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}