#include <malloc.h>
#include "stdio.h"

typedef struct ComplexNumber {
    int realPart;
    int imaginaryPart;
} ComplexNumber;

ComplexNumber *add(ComplexNumber *complexNumberOne, ComplexNumber *complexNumberTwo);

ComplexNumber *subtract(ComplexNumber *complexNumberOne, ComplexNumber *complexNumberTwo);

int add_integers(int a, int b);

int subtract_integers(int a, int b);

ComplexNumber *newComplexNumber(int realPart, int imaginaryPart);

int main() {
    ComplexNumber *complexNumberOne = newComplexNumber(1, 3);
    ComplexNumber *complexNumberTwo = newComplexNumber(5, 2);
    ComplexNumber *complexNumberThree = add(complexNumberOne, complexNumberTwo);
    ComplexNumber *complexNumberFour = subtract(complexNumberOne, complexNumberTwo);

    printf("ComplexNumberOne{realPart: %i, imaginaryPart: %i}", complexNumberOne->realPart, complexNumberOne->imaginaryPart);
    printf("\nComplexNumberTwo{realPart: %i, imaginaryPart: %i}", complexNumberTwo->realPart, complexNumberTwo->imaginaryPart);
    printf("\nComplexNumberThree{realPart: %i, imaginaryPart: %i}", complexNumberThree->realPart, complexNumberThree->imaginaryPart);
    printf("\nComplexNumberFour{realPart: %i, imaginaryPart: %i}", complexNumberFour->realPart, complexNumberFour->imaginaryPart);

    free(complexNumberOne);
    // TODO 03/12/2021 -> Warning Message "Local variable 'complexNumberTwo' may point to deallocated memory" Why?
    free(complexNumberTwo);
    free(complexNumberThree);
    free(complexNumberFour);
    return 0;
}

ComplexNumber *newComplexNumber(int realPart, int imaginaryPart) {
    ComplexNumber *complexNumber = malloc(sizeof(ComplexNumber));
    complexNumber->realPart = realPart;
    complexNumber->imaginaryPart = imaginaryPart;
    return complexNumber;
}

ComplexNumber *add(ComplexNumber *complexNumberOne, ComplexNumber *complexNumberTwo) {
    int realResult = add_integers(complexNumberOne->realPart, complexNumberTwo->realPart);
    int imaginaryResult = add_integers(complexNumberOne->imaginaryPart, complexNumberTwo->imaginaryPart);
    return newComplexNumber(realResult, imaginaryResult);
}

ComplexNumber *subtract(ComplexNumber *complexNumberOne, ComplexNumber *complexNumberTwo) {
    int realResult = subtract_integers(complexNumberOne->realPart, complexNumberTwo->realPart);
    int imaginaryResult = subtract_integers(complexNumberOne->imaginaryPart, complexNumberTwo->imaginaryPart);
    return newComplexNumber(realResult, imaginaryResult);
}

int add_integers(int a, int b) {
    return a + b;
}

int subtract_integers(int a, int b) {
    return a - b;
}