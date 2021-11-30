#include <stdio.h>

int main() {
    int num1, num2;
    printf("Input your two numbers, separated by spaces.\n>>");
    scanf("%d %d", &num1, &num2);

    // Your code here, which should swap the values of `num1` and `num2`
    int temp = num1;
    num1 = num2;
    num2 = temp;

    // Output to demonstrate whether you got this correct!
    printf("The value of num1 is now %d and the value of num is now %d.", num1, num2);
    return 0;
}