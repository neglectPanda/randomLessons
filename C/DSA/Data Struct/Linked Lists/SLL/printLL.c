#include <stdio.h>
#include "list.h"

void printList(NODE **head) {
    if(*head == NULL) {
        printf("list empty!\n\n");
        return;
    }

    NODE *temp = *head;
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    
    printf("\n\n");

    return;
}