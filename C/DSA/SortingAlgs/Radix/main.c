#include <stdio.h>

/*
    1. Find the maximum num in the array
    2. once found, get its # of digits
    3. countingSort(arr, arrSize, place)
        - place represents the digit place value we are currently sorting
        3.a) count the number of digits in max num
        3.b) count the cumulative number of digits
                - example: get the last digits of the array
                - from 0-9, count the number of occuerrneces per digit  
    4. sort the elements    
    5. copy the sorted array to the original
        - why? bcs ones we finish the "ones" digit sort, we need it
          as reference for the tens digit sorting... so on
    6. 
*/

int getMaxNum(int arr[], int arrSize);
int countingSort(int arr[], int);

int main(void) {

    return 0;
}

int getMaxNum(int arr[], int arrSize) {
    int maxEl = arr[0];
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] > maxEl) maxEl = arr[i];
    }
    return maxEl;
}