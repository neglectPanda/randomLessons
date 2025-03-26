#include <stdio.h>
#include "../tree.h"

int getHeight(NODE *root) {
    if(root == NULL) return 0;
    return root->height;
}