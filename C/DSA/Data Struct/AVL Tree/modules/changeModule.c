#include <stdio.h>
#include "../tree.h"

void changeModule(NODE **root) {
    int oldValue, newValue;
    printf("Enter value to change: ");
    
    if (scanf("%d", &oldValue) != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    while(getchar() != '\n'); // Clear input buffer

    printf("Enter new value: ");
    if (scanf("%d", &newValue) != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    while(getchar() != '\n'); // Clear input buffer

    // Delete old value
    *root = deleteNode(*root, oldValue);
    
    // Insert new value
    *root = insertNode(*root, newValue);

    printf("Value changed from %d to %d.\n", oldValue, newValue);
    displayTree(*root);
}