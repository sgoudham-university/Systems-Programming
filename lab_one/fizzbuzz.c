#include "stdio.h"

void printString(char *printString);

void printInt(int index);

int main() {
    int iterations = 0;
    printString("Enter How Many Iterations You Want:");
    scanf(" %i", &iterations);

    printString("\nOutput:");
    for (int i = 1; i <= iterations; i++) {
        if (i % 5 == 0 && i % 3 == 0) {
            printString("fizzbuzz");
        } else if (i % 5 == 0) {
            printString("buzz");
        } else if (i % 3 == 0) {
            printString("fizz");
        } else {
            printInt(i);
        }
    }

    return 0;
}

void printString(char *printString) {
    printf("%s\n", printString);
}

void printInt(int index) {
    printf("%i\n", index);
}
