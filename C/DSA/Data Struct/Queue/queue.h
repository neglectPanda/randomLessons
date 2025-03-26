#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} NODE;

typedef struct queue {
    NODE *front, *rear;
    int size;
} QUEUE;

void clearInputBuffer();
QUEUE *createQueue(int value);
int size(QUEUE *q);
bool isEmpty(QUEUE *q);
void printQueue(QUEUE *q, bool *status);
void enqueueModule(QUEUE *q); // check
int enqueue(QUEUE *q, int value); // check
void dequeueModule(QUEUE *q, bool *status);

#endif