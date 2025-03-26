#include <stdio.h>
#include "../tree.h"

void browse(NODE *root) {
    displayTree(root);
    printf("\n\n");
    breadthFirstTraversal(root);

    return;
}