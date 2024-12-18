#include <stdio.h>

void printElement(int *arr[], int size);

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *pArr[5];
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    //normal vars have 4 byte size
    //since there are five elements, and each of them contains 4 bytes, sizeof(arr) = 4 x 5 = 20
    //we are dividing it with an element's size, arr[0] = 4 bytes
    //we will get the proper size we are looking for

    for(int i = 0; i < arrSize; i++) {
        pArr[i] = &arr[i];
    }

    printElement(pArr, arrSize);

    return 0;
}

void printElement(int *arr[], int size) {
    for(int i = 0; i < size; i++) {
        *(arr + i);
        printf("Element %d: %d\n", i+1, *arr[i]);
    }
}