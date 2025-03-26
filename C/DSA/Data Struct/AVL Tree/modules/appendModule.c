#include <stdio.h>
#include "../tree.h"

void appendModule(NODE **root) {
    int value;
    char ch;

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {

            *root = insertNode(*root, value);
            printf("SUCCESS: node added!\n\n");
            displayTree(*root);

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }
}