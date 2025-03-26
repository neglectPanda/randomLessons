#include <stdio.h>
#include "../tree.h"

void deleteModule(NODE **root) {
    int value;
    char ch;

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {

            *root = deleteNode(*root, value);
            printf("SUCCESS: node deleted!\n\n");
            displayTree(*root);

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}