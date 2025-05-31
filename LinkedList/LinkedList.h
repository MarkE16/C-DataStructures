#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
    void* data;
    struct Node* next;
};

enum LinkedListType {
    STRING,
    CHARACTER,
    INTEGER
};

struct LinkedList {
    struct Node* head;
    enum LinkedListType type;
};


struct LinkedList* createLinkedList(enum LinkedListType);
struct Node* getNodeWithValue(struct LinkedList*, void*);
void append(struct LinkedList*, void*);
void removeNode(struct Node*);
void printLinkedList(struct LinkedList*);
void freeLinkedList(struct LinkedList**);

#endif // LINKEDLIST_H