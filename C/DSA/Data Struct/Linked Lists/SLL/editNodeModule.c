#include <stdio.h>
#include "list.h"

void editNodeModule(NODE **head) {
    if(*head == NULL) {
        printf("LIST empty!\n\n");
        return;
    }

    int oldVal, newVal;
    char ch;

    while(1) {
        printf("Enter value to edit: ");
        if((scanf("%d%c", &oldVal, &ch)) == 2 && ch == '\n') {

            if(searchNode(head, oldVal)) {
                printf("SUCCESS: node found!\n\n");

                printf("Enter new value: ");
                if((scanf("%d%c", &newVal, &ch)) == 2 && ch == '\n') {

                    if(editNode(head, oldVal, newVal)) {
                        printf("SUCCESS: node edited!\n\n");
                    } else {
                        printf("ERROR: node not edited!\n\n");
                    }

                } else {
                    printf("ERROR: value is of type int!\n\n");
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