#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node *next;
};

enum StackType {
    STRING,
    INTEGER,
    CHARACTER
};

struct Stack {
    unsigned int size;
    struct Node *top;
    enum StackType type;
};

struct Stack* createStack(enum StackType);
void push(struct Stack*, void*);
void* peek(struct Stack*);
struct Node* pop(struct Stack*);
void printStack(struct Stack*);
void freeStack(struct Stack**);

#endif // STACK_H