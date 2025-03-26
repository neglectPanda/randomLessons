#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

void initializeQueue(QUEUE *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(QUEUE *q) {
    return q->front == NULL;
}

void enqueue(QUEUE *q, NODE *root) {
    QUEUENODE *newNode = malloc(sizeof(QUEUENODE));
    newNode->node = root;
    newNode->next = NULL;

    if(isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

NODE *dequeue(QUEUE *q) {
    if (isQueueEmpty(q)) return NULL;

    QUEUENODE *temp = q->front;
    NODE *node = temp->node;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return node;
}

void freeQueue(QUEUE *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
}