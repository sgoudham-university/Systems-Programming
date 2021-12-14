#include "list.c"

int main() {
    // Create New List
    List *list = newList();

    // Add 10 Items To The List
    for (int i = 0; i < 10; i++) {
        List_append(list, i + 1);
    }

    // Print Out The Length Of The List
    // EXPECTED -> 10
    printf("Length Of List -> %i", List_length(list));

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
    List_destroy(list);

    return 0;
}