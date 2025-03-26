#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

void freeTree(NODE *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}