#include "stdio.h"

int collatzLength(int n);

int main() {
    printf("collatzLength(1) == %i\n", collatzLength(1));
    printf("collatzLength(16) == %i\n", collatzLength(16));
    printf("collatzLength(7) == %i\n", collatzLength(7));

    int longestSequence = 0;
    for (int i = 1; i <= 100; i++) {
        int currentSequence = collatzLength(i);
        if (currentSequence > longestSequence) {
            longestSequence = i;
        }
    }
    printf("\nLongest Collatz Sequence For The First 100 Numbers: %i", longestSequence);
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