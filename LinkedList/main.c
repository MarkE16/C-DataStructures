#include "LinkedList.h"

int main() {
    struct LinkedList *intList = createLinkedList(INTEGER);
    struct LinkedList *stringList = createLinkedList(STRING);
    struct LinkedList *charList = createLinkedList(CHARACTER);

    int x = 42;
    char* y = "Hello!";
    char z = 'c';

    append(intList, &x);
    append(stringList, y);
    append(charList, &z);

    int *item = (int*) findValue(intList, &x);

    if (item == NULL) {
        printf("Item x with value %d does not exist.\n", x);
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
