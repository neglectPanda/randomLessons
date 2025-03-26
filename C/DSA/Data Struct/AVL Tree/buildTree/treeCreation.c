#include <stdio.h>
#include <string.h>
#include "../tree.h"

void treeCreation(NODE **root, INPUT input) {
    for(int i = 0; i < input.size; i++) {
        printf("Inserting: %d\n", input.arr[i]);

        int ch;
        while((ch = getchar()) != ' ' && ch != '!') {
            if(ch == EOF) break;
        }

        if(ch == '!') break;

        *root = insertNode(*root, input.arr[i]);
        displayTree(*root);
    }
}