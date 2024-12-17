#include <stdio.h>

void printAge(int age);

int main() {
    int age = 21;
    int *pAge = &age; //pointers can be read as "value at address" 

    printf("Address: %p\n", pAge);
    printf("Value: %d\n", *pAge); //value at address age is 21 => dereferencing 

    //size
    printf("Size of age variable: %d\n", sizeof(age));
    printf("Size of pAge variable/pointer: %d\n", sizeof(pAge));

    //pointer contains 8 bytes => for hexadecimal address
    //normal variables contain 4 bytes

    printAge(*pAge);

    return 0;
}

void printAge(int age) {
    printf("You are %d years old.\n", age);
}