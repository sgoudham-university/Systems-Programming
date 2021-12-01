#include <malloc.h>
#include <string.h>
#include "stdio.h"

void number_to_word(int userInput);

char *convert_number_to_string(int userInput);

int main() {
    int userInput;
    printf("Please Enter A Number To Convert To Words:");
    scanf("%i", &userInput);
    number_to_word(userInput);
    return 0;
}

char *convert_number_to_string(int userInput) {
    int loopUserInput = userInput;
    int digit = 0;
    while (loopUserInput) {
        digit++;
        loopUserInput /= 10;
    }

    char *numberArray = malloc((digit + 2) * sizeof(char));
    sprintf(numberArray, "%i", userInput);

    return numberArray;
}

void number_to_word(int userInput) {
    char *numberArray = convert_number_to_string(userInput);
    for (int i = 0; i < strlen(numberArray); i++) {
        switch (numberArray[i]) {
            case '-':
                printf("negative\n");
                break;
            case '0':
                printf("zero\n");
                break;
            case '1':
                printf("one\n");
                break;
            case '2':
                printf("two\n");
                break;
            case '3':
                printf("three\n");
                break;
            case '4':
                printf("four\n");
                break;
            case '5':
                printf("five\n");
                break;
            case '6':
                printf("six\n");
                break;
            case '7':
                printf("seven\n");
                break;
            case '8':
                printf("eight\n");
                break;
            case '9':
                printf("zero\n");
                break;
        }
    }
    free(numberArray);
}
