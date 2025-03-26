#include <stdio.h>
#include "../tree.h"

int calculateTreeHeight(NODE *root) {
    if (root == NULL) return 0;
    
    int leftHeight = calculateTreeHeight(root->left);
    int rightHeight = calculateTreeHeight(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}