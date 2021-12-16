#include "list.h"

List *List_createList(int maxSize, int currentSize);

typedef struct list {
    int *_array;
    int _currentSize;
    int _maxSize;
} List;

List *newList() {
    return List_createList(10, -1);
}

int List_get(List *list, int index) {
    if (index < 0 || index >= list->_currentSize) {
//        printf("[ERRNO 004]\n");
        return INT_MAX;
    }
    return list->_array[index];
}

void List_append(List *list, int element) {
    if (element == INT_MAX) {
        printf("[ERRNO 005]\n");
        return;
    }

    if (list->_currentSize + 1 == list->_maxSize) {
        list->_maxSize *= 2;
        int *temp = realloc(list->_array, list->_maxSize * sizeof(int));
        if (!temp) {
//            printf("[ERRNO 003]\n");
            return;
        } else {
            list->_array = temp;
        }
    }
    list->_array[++list->_currentSize] = element;
}

void List_remove(List *list, int element) {
    int positionToDelete = INT_MAX;
    for (int i = 0; i < list->_currentSize + 1; i++) {
        if (list->_array[i] == element) {
            positionToDelete = i;
        }
    }

    if (positionToDelete == INT_MAX) {
//        printf("[ERRNO 006]\n");
        return;
    }

    for (int i = positionToDelete; i < list->_currentSize + 1; i++) {
        list->_array[i] = list->_array[i + 1];
    }

    list->_currentSize--;
}

void List_sort(List *list) {

}

List *List_copy(List *list) {
    List *listCopy = List_createList(list->_maxSize, list->_currentSize);
    if (!listCopy) {
        return NULL;
    }

    for (int i = 0; i < list->_currentSize + 1; i++) {
        listCopy->_array[i] = list->_array[i];
    }

    return listCopy;
}

List *List_slice(List *list, int start_index, int end_index) {

}

int List_length(List *list) {
    return list->_currentSize + 1;
}

void List_print(List *list) {
    printf("\n[");
    for (int i = 0; i < list->_currentSize + 1; i++) {
        if (i == list->_currentSize) {
            printf("%i", list->_array[i]);
        } else {
            printf("%i, ", list->_array[i]);
        }
    }
    printf("]");
}

void List_destroy(List *list) {
    free(list->_array);
    list->_array = NULL;
    free(list);
}

List *List_createList(int maxSize, int currentSize) {
    List *list = malloc(sizeof(List));
    if (!list) {
//        printf("[ERRNO 001]\n");
        return NULL;
    }

    list->_array = calloc(maxSize, sizeof(int));
    if (!list->_array) {
//        printf("[ERRNO 002]\n");
        free(list);
        return NULL;
    }

    list->_maxSize = maxSize;
    list->_currentSize = currentSize;

    return list;
}