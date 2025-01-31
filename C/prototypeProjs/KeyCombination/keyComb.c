#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define PASSCODE 1234

int generatePasscode();

int main() {
    bool condition = true;
    int passcodeGen;

    while(condition) {
        passcodeGen = generatePasscode();

        if(passcodeGen == PASSCODE) {
            printf("Found passcode!\n");
            break;
        }
    }

    return 0;
}

int generatePasscode() {
    int passcode;

    passcode = 1000 + rand() % 9000;

    return passcode;
}