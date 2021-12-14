#include "stdlib.h"
#include "stdio.h"

typedef struct List List;

List *newList();

void List_append(struct List *list, int element);

void List_remove(struct List *list, int element);

void List_sort(struct List *list);

int List_length(struct List *list);

void List_print(struct List *list);

void List_destroy(struct List *list);