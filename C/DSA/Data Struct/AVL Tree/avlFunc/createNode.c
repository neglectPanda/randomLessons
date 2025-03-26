#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

NODE *createNode(int value) {
    NODE *node = (NODE *)malloc(sizeof(NODE));

    if(node == NULL) {
        printf("ERROR: malloc failed!\n\n");
        exit(1);
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->status = 0;

    return node;
}