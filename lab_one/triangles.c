#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c;
    printf("Input your longest side:");
    scanf("%d", &c); // A is biggest.
    printf("Input your second longest side:");
    scanf("%d", &a); // b is next
    printf("Input your smallest side:");
    scanf("%d", &b); // c is smallest!

    // Your code here. Assume a > b > c.
    int a_squared = a * a;
    int b_squared = b * b;
    int c_squared = a_squared + b_squared;
    int c_squared_hypotenuse = c * c;

    char output[5];
    if (c_squared == c_squared_hypotenuse) {
        strcpy(output, "True");
    } else {
        strcpy(output, "False");
    }

    printf("Is This A Right Angled Triangle? %s", output);
    return 0;
}