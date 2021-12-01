#include "stdio.h"

int collatzSequence(int n);

int main() {
    collatzSequence(6);
}

int collatzSequence(int n) {
    if (n == 1) {
        printf("%i", n);
        return 0;
    } else if (n % 2 == 0) {
        printf("%i -> ", n);
        return collatzSequence(n / 2);
    } else if (n % 2 == 1) {
        printf("%i -> ", n);
        return collatzSequence(3 * n + 1);
    }
    return 0;
}