#include <stdio.h>
#include "list.h"

int editNode(NODE **head, int oldVal, int newVal) {
    if(*head == NULL) return 0;

    NODE *current = *head;
    //traversal
    while(current != NULL && current->value != oldVal) {
        current = current->next;
    }

    current->value = newVal;
    return 1; //success
}