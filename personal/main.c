#include "list.h"

/*
 * -- IMPORTANT --
 * 2147483647 -> 2147483642 is reserved to be returned for ERRORS and therefore cannot be inserted into this Dynamic List
 */

/*
 * -- ERROR CODES --
 *
 * [ERRNO 2147483647] -> Cannot Allocate Memory To List
 * [ERRNO 2147483646] -> Cannot Allocate Memory To Backing Array
 * [ERRNO 2167483645] -> Cannot Reallocate Memory To Backing Array
 * [ERRNO 2147483644] -> Index Out Of Bounds For Retrieving Element
 * [ERRNO 2147483643] -> Value 2147483647 Cannot Be Inserted Into List
 * [ERRNO 2147483642] -> Element Does Not Exist Within List
 */


int main() {

    // Create New List
    List *list = newList();

    // Add 10 Items To The List
    for (int i = 0; i < 10; i++) {
        List_append(list, i + 1);
    }

    // Slice The List
    // EXPECTED -> [1, 2, 3, 4, 5]
    List *slicedList = List_slice(list, 2, 4);

    // Copy List Into ListCopy
    List *listCopy = List_copy(list);

    // Retrieve The 5th Element Of The List
    // EXPECTED -> 5
    printf("Element At Index 5 -> '%i'", List_get(list, 5));

    // Print Out The Length Of The List
    // EXPECTED -> 10
    printf("\nLength Of List -> %i", List_length(list));

    // Force List To Dynamically Resize With 11th Element
    // EXPECTED -> List resized to hold 20 elements and 11 appended into list
    List_append(list, 11);

    // Print Out The Length Of The List
    // EXPECTED -> 11
    printf("\nLength Of List -> %i", List_length(list));

    // Try To Remove Element That Does Not Exist Within List
    // EXPECTED -> ERROR 20 Does Not Exist Within List
    List_remove(list, 20);

    // Print Out All Elements Within List
    // EXPECTED -> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    List_print(list);

    // Remove Element Within List
    // EXPECTED -> Element '5' removed from list
    List_remove(list, 5);

    // Print Out The Length Of The List
    // EXPECTED -> 10
    printf("\nLength Of List -> %i", List_length(list));

    // Print Out All Elements Within List
    // EXPECTED -> [1, 2, 3, 4, 6, 7, 8, 9, 10, 11]
    List_print(list);

    // Free Up The Memory Allocated For The List
    // EXPECTED -> Memory Freed
    if (list) {
        List_destroy(&list);
    }
    if (listCopy) {
        List_destroy(&listCopy);
    }

    return 0;
}