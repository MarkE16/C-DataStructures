#include "LinkedList.h"

void printNode(enum LinkedListType type, void *d) {
    switch (type) {
        case STRING:
            printf("%s\n", (char*) d);
            break;
        case CHARACTER:
            printf("%c\n", *(char*)d);
            break;
        case INTEGER:
            printf("%d\n", *(int*) d);
            break;
    }
}

int compareValues(enum LinkedListType type, void *d1, void *d2) {
    switch (type) {
        case INTEGER:
            return (*(int*)d1 - *(int*) d2);
        case CHARACTER:
            return (*(char*)d1 - *(char*) d2);
        case STRING:
            return strcmp((char*) d1, (char*) d2);
        default:
            return 0;
    }
}

/**
 * Create a pointer to a LinkedList.
 */
struct LinkedList* createLinkedList(enum LinkedListType type) {
    struct LinkedList *ptr = malloc(sizeof(struct LinkedList));
    ptr->head = NULL;
    ptr->type = type;

    return ptr;
}

void* findValue(struct LinkedList *list, void *value) {
    if (list == NULL) { return NULL; }
    struct Node *current = list->head;

    while (current != NULL && compareValues(list->type, current->data, value) != 0) {
        current = current->next;
    }

    return current->data;
}

/**
 * Add a value to the end of the LinkedList.
 */
void append(struct LinkedList *list, void *value) {
    if (list == NULL) { return; }
    struct Node *node = malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        return;
    }

    struct Node *current = list->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = node;
}

/**
 * Print the LinkedList.
 */
void printLinkedList(struct LinkedList *list) {
    struct Node *current = list->head;

    while (current) {
        printNode(list->type, current->data);
        current = current->next;
    }
}

void removeNode(struct Node *n) {
    // ...
}

/**
 * Free the LinkedList.
 */
void freeLinkedList(struct LinkedList **list) {
    struct LinkedList *l = *list;
    
    if (l == NULL) { return; }
    
    while (l->head) {
        struct Node* tmp = l->head;
        l->head = l->head->next;

        free(tmp);
    }

    // Free the allocated list.
    free(l);

    // Set to NULL to prevent use-after-free
    *list = NULL;
}
