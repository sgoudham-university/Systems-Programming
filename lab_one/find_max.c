#include <stdio.h>

int main() {
    int max = 0;
    int curr;
    int i;
    for (i = 0; i < 10; i++) {
        printf("Input the next number:");
        scanf("%d", &curr);
        if (curr > max) {
            max = curr;
        }
    }
    printf("\nThe Max Is: %i", max);
    return 0;
}