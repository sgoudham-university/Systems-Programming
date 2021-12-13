#include "list.h"

typedef struct List {
    int *array;
    int usedSize;
    int maxSize;

    void (*append)(struct List *list, int element);

    void (*remove)(struct List *list, int element);

    int (*length)(struct List *list);

    void (*print)(struct List *list);

    void (*destroy)(struct List *list);
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
    list->usedSize = 0;
    list->append = &append;
    list->remove = &delete;
    list->length = &length;
    list->print = &print;
    list->destroy = &destroyList;

    return list;
}

void destroyList(struct List *list) {
    free(list->array);
    list->array = NULL;
    free(list);
}

void append(struct List *list, int element) {
    if (list->usedSize == list->maxSize) {
        list->maxSize *= 2;
        list->array = realloc(list->array, list->maxSize * sizeof(int));
        // TODO: Question For Tom: How do I handle realloc failure? // What's the best way to handle a failure like this?
    }
    list->array[list->usedSize++] = element;
}

void delete(struct List *list, int element) {
    int positionToDelete = -1;
    for (int i = 0; i < list->usedSize; i++) {
        if (list->array[i] == element) {
            positionToDelete = i;
        }
    }

    if (positionToDelete == -1) {
        printf("\nElement '%i' Does Not Exist Within List", element);
        return;
    }

    for (int i = positionToDelete; i < list->usedSize; i++) {
        list->array[i] = list->array[i + 1];
    }

    list->usedSize -= 1;
}

int length(struct List *list) {
    return list->usedSize;
}

void print(struct List *list) {
    printf("\n[");
    for (int i = 0; i < list->usedSize; i++) {
        if (i == list->usedSize - 1) {
            printf("%i", list->array[i]);
        } else {
            printf("%i, ", list->array[i]);
        }
    }
    printf("]");
}