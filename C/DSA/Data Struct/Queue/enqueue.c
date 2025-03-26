#include <stdio.h>
#include "queue.h"

int enqueue(QUEUE *q, int value) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL) return 0; //success

    newNode->value = value;
    newNode->next = NULL;

    if(q->rear == NULL) {
        q->rear = newNode;
        q->front = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
    return 1; // success
}