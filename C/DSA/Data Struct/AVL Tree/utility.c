#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "tree.h"

void displayMenu() {
    printf("\n=== MAIN MENU ===\n");
    printf("[A] - Append Node\n");
    printf("[B] - Browse\n");
    printf("[C] - Change Node\n");
    printf("[D] - Delete Node\n");
    printf("[E] - Exit\n");

    return;
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

void mainMenu(NODE **root) {
    char choice;
    bool isRunning = true;

    while(isRunning) {
        displayMenu();
        printf("Choice: ");
        scanf("%c", &choice);
        clearInputBuffer();

        switch(toupper(choice)) {
            case 'A':
                appendModule(root);
                break;
            case 'B':
                browse(*root);
                break;
            case 'C':
                changeModule(root);
                break;
            case 'D':
                deleteModule(root);
                break;
            case 'E':
                printf("Exiting...\n\n");
                isRunning = false;
                return;
            default:
                printf("ERROR: invalid choice\n\n");
        }
    }
}

NODE *findMinNode(NODE *root) {
    NODE *current = root;
    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}