#ifndef LIST_H
#define LIST_H

typedef struct node {
    int value;
    struct node *next, *prev;
} NODE;

NODE *createNode(int value);
void clearInputBuffer();

void addNodeModule(NODE **head);
int addNode(NODE **head, int value);
int searchNode(NODE **head, int value);
void editNodeModule(NODE **head);
int editNode(NODE **head, int oldVal, int newVal);
void deleteNodeModule(NODE **head);
int deleteNode(NODE **head, int target);
void printList(NODE **head);

#endif