#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct name {
    char name[20];
} NAME;

int main(void) {
    //malloc will allocate space for a specific sturcture

    //size of your struct
    //it only contains name that takes in 20 characters max
    //so size is 20

    //the hardware will allocate memory size of 20 bytes for the struct name
    //and be stored at a pointer NAME*

    NAME *name = (NAME *) malloc(sizeof(NAME));
    printf("%d\n", sizeof(*name));

    //to prevent memory leaks
    free(name);

    //its name and not *name because *name will just deal with the content instead of the variable

    return 0;
}
