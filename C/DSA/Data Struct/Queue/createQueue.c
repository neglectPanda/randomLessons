#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QUEUE *createQueue(int value) {
    QUEUE *newQueue = (QUEUE *)malloc(sizeof(QUEUE));
    if(newQueue == NULL) {
        printf("ERROR: malloc failed!\n\n");
        free(newQueue);
        return NULL;
    }

    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;

    return newQueue;
}