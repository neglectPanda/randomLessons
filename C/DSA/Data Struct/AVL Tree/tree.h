#ifndef TREE_H
#define TREE_H

#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

typedef struct node {
    int value, height;
    struct node *left, *right;
    int status;
} NODE;

typedef struct {
    int *arr;
    int size;
} INPUT;

/* breadth first search */
typedef struct queueNode {
    NODE *node;
    struct queueNode *next;
} QUEUENODE;

typedef struct {
    QUEUENODE *front, *rear;
} QUEUE;

// input
INPUT inputModule();
void clearInputBuffer();
void displayMenu();
void mainMenu(NODE **root);
void freeTree(NODE *root);

// module functions
void appendModule(NODE **root);
void browse(NODE *root);
void deleteModule(NODE **root);
void changeModule(NODE **root);

// node functions
NODE *createNode(int value);
NODE *insertNode(NODE *root, int value);
NODE *findMinNode(NODE *root);
NODE* deleteNode(NODE *root, int value);

// calculations
int getHeight(NODE *root);
int balanceFactor(NODE *root);
int calculateTreeHeight(NODE *root);

// rotations
NODE *rotateRight(NODE *root);
NODE *rotateLeft(NODE *root);

// building tree
void treeCreation(NODE **root, INPUT input);
void displayTree(NODE *root);
void printTree(NODE *root, char *buffer[], int height, int level, int col, int row);
void printBuffers(char *buffer[], int height);

// queue
void initializeQueue(QUEUE *q);
int isQueueEmpty(QUEUE *q);
void enqueue(QUEUE *q, NODE *root);
NODE *dequeue(QUEUE *q);
void freeQueue(QUEUE *q);

void breadthFirstTraversal(NODE *root);

#endif