#include "list.h"

typedef struct List {
    int *array;
    int currentSize;
    int maxSize;
} List;

List *newList() {
    List *list = malloc(sizeof(List));
    if (!list) {
        printf("\nCannot Allocate Memory To List -> Returning NULL");
        return NULL;
    }

    list->array = calloc(10, sizeof(int));
    if (!list->array) {
        printf("\nCannot Allocate Memory To Array Within List -> Aborting Operation");
        free(list);
        return NULL;
    }

    list->maxSize = 10;
    list->currentSize = 0;

    return list;
}

void List_destroy(struct List *list) {
    free(list->array);
    list->array = NULL;
    free(list);
}

void List_append(struct List *list, int element) {
    if (list->currentSize == list->maxSize) {
        list->maxSize *= 2;
        list->array = realloc(list->array, list->maxSize * sizeof(int));
        // TODO: Question For Tom: How do I handle realloc failure? // What's the best way to handle a failure like this?
    }
    list->array[list->currentSize++] = element;
}

void List_remove(struct List *list, int element) {
    int positionToDelete = -1;
    for (int i = 0; i < list->currentSize; i++) {
        if (list->array[i] == element) {
            positionToDelete = i;
        }
    }

    if (positionToDelete == -1) {
        printf("\nElement '%i' Does Not Exist Within List", element);
        return;
    }

    for (int i = positionToDelete; i < list->currentSize; i++) {
        list->array[i] = list->array[i + 1];
    }

    list->currentSize -= 1;
}

int List_length(struct List *list) {
    return list->currentSize;
}

void List_print(struct List *list) {
    printf("\n[");
    for (int i = 0; i < list->currentSize; i++) {
        if (i == list->currentSize - 1) {
            printf("%i", list->array[i]);
        } else {
            printf("%i, ", list->array[i]);
        }
    }
    printf("]");
}