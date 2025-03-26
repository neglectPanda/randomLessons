#include <stdio.h>
#include <stdlib.h>
#include "list.h"

NODE *createNode(int value) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    if(newNode == NULL) return NULL;

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}