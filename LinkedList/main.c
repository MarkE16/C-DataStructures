#include "LinkedList.h"

int main() {
    struct LinkedList *intList = createLinkedList(INTEGER);
    struct LinkedList *stringList = createLinkedList(STRING);
    struct LinkedList *charList = createLinkedList(CHARACTER);

    int* x = malloc(sizeof(int));
    char* y = malloc(strlen("Hello!") + 1);
    char* z = malloc(sizeof(char));

    // strcpy is deprecated and not safe; however,
    // I will use it for the sake of demonstration.
    strcpy(y, "Hello");

    *x = 32;
    *z = 'b';
    append(intList, x);
    append(stringList, y);
    append(charList, z);

    struct Node* item = getNodeWithValue(intList, x);

    if (item == NULL) {
        printf("Item x with value %d does not exist.\n", *x);
    } else {
        printf("Item x exists.\n");
    }

    printLinkedList(intList);
    printLinkedList(stringList);
    printLinkedList(charList);

    freeLinkedList(&intList);
    freeLinkedList(&stringList);
    freeLinkedList(&charList);
    return 0;
}
