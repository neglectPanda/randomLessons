#include <stdio.h>
#include "queue.h"

void enqueueModule(QUEUE *q) {
    int value;
    char ch;

    printf("\n=== ENQUEUE MODULE ===\n");

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {

            if(enqueue(q, value)) {
                printf("SUCCESS: node added!\n\n");
            } else {
                printf("ERROR: node not added!\n\n");
            }

        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}