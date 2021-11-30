#include <stdio.h>

int fibonacci(int n);

void printString(char *printString);

void printInt(int index);

void specialPrintInt(int index);

int main() {
    int iterations = 0;
    printString("Enter No. of Fibonacci Numbers You Want To See:");
    scanf(" %i", &iterations);

    printf("[");
    for (int i = 0; i < iterations; i++) {
        if (i == iterations - 1) {
            specialPrintInt(fibonacci(i));
        } else {
            printInt(fibonacci(i));
        }
    }
    printf("]");

    return 0;
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

void printString(char *printString) {
    printf("%s\n", printString);
}

void printInt(int index) {
    printf("%i, ", index);
}

void specialPrintInt(int index) {
    printf("%i", index);
}