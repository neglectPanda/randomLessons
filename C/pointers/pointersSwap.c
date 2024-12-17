#include <stdio.h>

void printSwap(int *a, int *b);

int main() {
    int a, b;
    int *pA, *pB;
    pA = &a;
    pB = &b;

    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    printSwap(pA, pB);

    return 0;
}

void printSwap(int *a, int *b) {
    int temp;

    //let's say a = 5, b = 10

    temp = *a;
    //temp = 5

    *a = *b;
    //*a = 10

    *b = temp;
    //*b = 5

    printf("After swapping: a = %d, b = %d\n", *a, *b);    
}