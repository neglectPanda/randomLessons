#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {
    NODE *root = NULL;
    INPUT input;

    // Input Numbers
    input = inputModule();

    // Step by Step Tree Creation
    treeCreation(&root, input);

    // Free input array after using
    free(input.arr);

    // Main Menu
    mainMenu(&root);

    // Free the tree before exiting
    freeTree(root);

    return 0;
}