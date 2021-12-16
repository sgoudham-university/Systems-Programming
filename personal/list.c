#include "list.h"

/*
 * -- ERROR CODES --
 *
 * [ERRNO 2147483647] -> Cannot Allocate Memory To List
 * [ERRNO 2147483646] -> Cannot Allocate Memory To Backing Array
 * [ERRNO 2167483645] -> Cannot Reallocate Memory To Backing Array
 * [ERRNO 2147483644] -> Index Out Of Bounds For Retrieving Element
 * [ERRNO 2147483643] -> Values 2147483647 -> 2147483642 Cannot Be Inserted Into List
 * [ERRNO 2147483642] -> Element Does Not Exist Within List
 */

List *List_createList(int maxSize, int currentSize);

typedef struct list {
    int *_array;
    int _currentSize;
    int _maxSize;
} List;

int errorCodes[ERRNO_SIZE] = {
        ERRNO_001,
        ERRNO_002,
        ERRNO_003,
        ERRNO_004,
        ERRNO_005,
        ERRNO_006
};

List *newList() {
    return List_createList(10, -1);
}

int List_get(List *list, int index) {
    if (index < 0 || index >= list->_currentSize) {
        return ERRNO_004;
    }
    return list->_array[index];
}

int List_append(List *list, int element) {
    for (int i = 0; i < ERRNO_SIZE; i++) {
        if (element == errorCodes[i]) {
            return ERRNO_005;
        }
    }

    if (list->_currentSize + 1 == list->_maxSize) {
        list->_maxSize *= 2;
        int *temp = realloc(list->_array, list->_maxSize * sizeof(int));
        if (!temp) {
            return ERRNO_003;
        }
        list->_array = temp;
    }
    list->_array[++list->_currentSize] = element;

    return 0;
}

int List_remove(List *list, int element) {
    int positionToDelete = -1;
    for (int i = 0; i < list->_currentSize + 1; i++) {
        if (list->_array[i] == element) {
            positionToDelete = i;
        }
    }

    if (positionToDelete == -1) {
        return ERRNO_006;
    }

    for (int i = positionToDelete; i < list->_currentSize + 1; i++) {
        list->_array[i] = list->_array[i + 1];
    }
    list->_currentSize--;

    return 0;
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
    if (start_index >= end_index) {
        return NULL;
    }

    int slicedCurrentSize = end_index - start_index;
    int slicedMaxSize = slicedCurrentSize * 2;
    List *slicedList = List_createList(slicedMaxSize, slicedCurrentSize);
    if (!slicedList) {
        return NULL;
    }

    int i = 0;
    for (int j = start_index; j < end_index; j++) {
        slicedList->_array[i] = list->_array[j];
        i++;
    }

    return slicedList;
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

void List_destroy(List **list) {
    free((*list)->_array);
    (*list)->_array = NULL;
    free(*list);
    *list = NULL;
}

List *List_createList(int maxSize, int currentSize) {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }

    list->_array = calloc(maxSize, sizeof(int));
    if (!list->_array) {
        free(list);
        return NULL;
    }

    list->_maxSize = maxSize;
    list->_currentSize = currentSize;

    return list;
}