#include <stdio.h>
#include "list.h"

int addNode(NODE **head, int value) {
    NODE *temp = createNode(value);

    if(temp == NULL) return 0; //malloc failed

    if(*head == NULL) {
        *head = temp;
        return 1; // success
    }

    NODE *newNode = *head;
    while(newNode->next != NULL) {
        newNode = newNode->next;
    }
    newNode->next = temp;
    temp->prev = newNode;
    return 1; // success
}