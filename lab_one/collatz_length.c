#include "stdio.h"

int collatzLength(int n);

int main() {
    printf("collatzLength(1) == %i\n", collatzLength(1));
    printf("collatzLength(16) == %i\n", collatzLength(16));
    printf("collatzLength(7) == %i\n", collatzLength(7));
}

int collatzLength(int n) {
    int counter = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        counter++;
    }
    return counter;
}