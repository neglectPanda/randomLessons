#include <stdio.h>
#include "../tree.h"

int balanceFactor(NODE *root) {
    if(root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}