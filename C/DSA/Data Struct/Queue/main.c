#include <stdio.h>
#include "queue.h"

void displayMenu();

int main(void) {

    int choice;
    char ch;
    QUEUE *q = NULL;

    while(1) {
        displayMenu();
        printf("Enter choice: ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {

            switch(choice) {
                case 1:
                    //enqueueModule(q);
                    break;
                case 2:
                    //dequeueModule();
                    break;
                case 3:
                    //size();
                    break;
                case 4:
                    //printQueue();
                    break;
                case 5:
                    printf("EXITING...\n\n");
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

void displayMenu() {
    printf("[1] - Enqueue\n");
    printf("[2] - Dequeue\n");
    printf("[3] - Size\n");
    printf("[4] - Print Queue\n");
    printf("[5] - Exit\n");
}

void clearInputBufeer() {
    while(getchar()!='\n');
}