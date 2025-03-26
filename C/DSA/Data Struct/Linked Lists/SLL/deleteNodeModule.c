#include <stdio.h>
#include "list.h"

void deleteNodeModule(NODE **head) {
    if(*head == NULL) {
        printf("LIST empty!\n\n");
        return;
    } //empty nothing to delete

    int value;
    char ch;

    printf("\n=== DELETE NODE ===\n");
    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {

            if(searchNode(head, value)) {
                printf("SUCCESS: node found!\n\n");

                if(deleteNode(head, value)) {
                    printf("SUCCESS: node deleted!\n\n");
                } else {
                    printf("ERROR: node not found!\n\n");
                }

            } else {
                printf("ERROR: node not found!\n\n");
            }

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}