#include <stdio.h>
#include "list.h"

int searchNode(NODE **head, int value) {
    NODE *temp = *head;

    //traversal
    while(temp != NULL) {
        if(temp->value == value) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;

}