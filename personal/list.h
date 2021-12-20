#include "stdlib.h"
#include "stdio.h"

#define INT_MAX 2147483647
#define ERRNO_002 2147483646
#define ERRNO_003 2147483645
#define ERRNO_004 2147483644
#define ERRNO_005 2147483643
#define ERRNO_006 2147483642
#define ERRNO_SIZE 5

typedef struct list List;

List *newList();

/*
 * Function: List_get
 * ----------------------------
 *  Retrieve an element from the list at the given index
 *
 *  *list: the list to append onto
 *  index: the index of the list to retrieve
 *
 *  returns: int
 */
int List_get(List *list, int index);

/*
 * Function: List_append
 * ----------------------------
 *  Appends an element onto the end of the list
 *
 *  *list: the list to append onto
 *  element: the element to insert into the list
 *
 *  returns: int
 */
int List_append(List *list, int element);

/*
 * Function: List_remove
 * ----------------------------
 *  Appends an element onto the end of the list
 *
 *  *list: the list to append onto
 *  element: the element to insert into the list
 *
 *  returns: void
 */
int List_remove(List *list, int element);

void List_sort(List *list);

List *List_copy(List *list);

List *List_slice(List *list, int start_index, int end_index);

int List_length(List *list);

void List_print(List *list);

void List_destroy(List **list);