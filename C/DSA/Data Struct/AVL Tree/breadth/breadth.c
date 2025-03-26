#include <stdio.h>
#include "../tree.h"

void breadthFirstTraversal(NODE *root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    QUEUE q;
    initializeQueue(&q);
    enqueue(&q, root);

    printf("Breadth-First Traversal: ");
    while (!isQueueEmpty(&q)) {
        NODE *current = dequeue(&q);
        printf("%d ", current->value);

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
    printf("\n");

    freeQueue(&q);
}