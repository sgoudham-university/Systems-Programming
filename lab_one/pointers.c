#include <stdlib.h>
#include <stdio.h>

typedef struct number {
    int num;
} number_t;

number_t *createNewNumber(int num);

void doOperationWithSinglePointer(number_t *number);

void doOperationWithDoublePointer(number_t **number);

void doOperationWithTriplePointer(number_t **number);

void freeWithSinglePointer(number_t *number);

void freeWithDoublePointer(number_t **number);

void freeWithTriplePointer(number_t ***number);

int main() {
    // Create New Numbers
    number_t *numberOne = createNewNumber(1);
    number_t *numberTwo = createNewNumber(2);
    number_t *numberThree = createNewNumber(3);

    // Do Operation When Passing In Single Pointer
    // THIS DOES NOT WORK
    doOperationWithSinglePointer(numberOne);

    // Do Operation When Passing in Double Pointer
    // This works
    doOperationWithDoublePointer(&numberTwo);

    // Do Operation When Passing in Triple Pointer
    // This works
    doOperationWithTriplePointer(&numberThree);

    /* What is happening here:
     *  - A pointer is passed to a doOperation() method which is then called to a free function
     *  - Setting the variable NULL inside the nested function WILL NOT keep its value when traversing back up functions
     *  - This is because variables are passed by values (effectively creating a local copy of it on the stack)
     *  */

    printf("numberOne -> %i", numberOne);
    printf("\nnumberTwo -> %s", numberTwo);
    printf("\nnumberThree -> %s", numberThree);

    return 0;
}

number_t *createNewNumber(int num) {
    number_t *myNumber = malloc(sizeof(number_t));
    myNumber->num = num;
    return myNumber;
}

void doOperationWithSinglePointer(number_t *number) {
    // Do An Operation Then Free The Number Node

    freeWithSinglePointer(number);
}

void doOperationWithDoublePointer(number_t **number) {
    // Do an Operation Then Free The Number Node

    freeWithDoublePointer(number);
}

void doOperationWithTriplePointer(number_t **number) {
    // Do an Operation Then Free The Number Node

    freeWithTriplePointer(&number);
}

void freeWithSinglePointer(number_t *number) {
    free(number);
    number = NULL;
}

void freeWithDoublePointer(number_t **number) {
    free(*number);
    *number = NULL;
}

void freeWithTriplePointer(number_t ***number) {
    free(**number);
    **number = NULL;
}