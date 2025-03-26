#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int deleteNode(NODE **head, int target) {
    NODE *temp = *head;

    // if head is the target
    if(target == temp->value) {
        *head = temp->next;

        if(*head != NULL) (*head)->prev = NULL;

        free(temp);
        return 1; // success
    }

    // traversal til we find the target node
    while(temp != NULL && target != temp->value) {
        temp = temp->next;
    }

    if(temp == NULL) return 0;

    if(temp->prev != NULL) temp->prev->next = temp->next;
    if(temp->next != NULL) temp->next->prev = temp->prev;

    free(temp);
    return 1;
    
}