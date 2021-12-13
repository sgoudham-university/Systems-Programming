#include "stdlib.h"
#include "stdio.h"

typedef struct List List;

List *newList();

void append(struct List *list, int element);

void delete(struct List *list, int element);

int length(struct List *list);

void print(struct List *list);

void destroyList(struct List *list);