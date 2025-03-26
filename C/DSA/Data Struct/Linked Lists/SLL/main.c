#include <stdio.h>
#include "list.h"

void displayMenu();

int main(void) {
    int choice;
    char ch;

    NODE *head = NULL;

    while(1) {
        displayMenu();
        printf("Choice: ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {

            switch(choice) {
                case 1:
                    addNodeModule(&head);
                    break;
                case 2:
                    deleteNodeModule(&head);
                    break;
                case 3:
                    editNodeModule(&head);
                    break;
                case 4:
                    printList(&head);
                    break;
                case 5:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("ERROR: invalid choice!\n\n");
            }

        } else {
            printf("ERROR: choice is of type int!\n\n");
            clearInputBuffer(); 
        }
    }

    return 0;
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

void displayMenu() {
    printf("[1] - Append node\n");
    printf("[2] - Delete node\n");
    printf("[3] - Edit node\n");
    printf("[4] - Print node\n");
    printf("[5] - Exit\n");
}