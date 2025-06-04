#include "Stack.h"

void printNode(enum StackType type, void *d) {
    switch (type) {
        case INTEGER:
            printf("%d\n", *(int*)d);
            break;
        case STRING:
            printf("%s\n", (char*)d);
            break;
        case CHARACTER:
            printf("%c\n", *(char*)d);
            break;
        default:
            break;
    }
}

struct Stack* createStack(enum StackType type) {
    struct Stack *ptr = (struct Stack*) malloc(sizeof(struct Stack));

    ptr->top = NULL;
    ptr->size = 0;
    ptr->type = type;

    return ptr;
}

void push(struct Stack *s, void *d) {
    if (s == NULL) { return; }

    struct Node *n = (struct Node*) malloc(sizeof(struct Node));
    n->data = d;
    n->next = s->top;
    s->top = n;
    s->size++;
}

void* peek(struct Stack* s) {
    if (s == NULL) { return NULL; }
    if (s->top == NULL) { return NULL; }

    return s->top->data;
}

struct Node* pop(struct Stack* s) {
    if (s == NULL) { return NULL; }
    if (s->top == NULL) { return NULL; }

    struct Node* n = s->top;
    s->top = s->top->next;

    return n;
}

// Prints the stack.
void printStack(struct Stack *s) {
    if (s == NULL) { return; }

    struct Node *current = s->top;

    while (current != NULL) {
        printNode(s->type, current->data);
        current = current->next;
    }
}

void freeStack(struct Stack** s) {
    struct Stack *stack = *s;

    if (stack == NULL) { return; }

    struct Node *current = stack->top;

    while (current != NULL) {
        struct Node *tmp = current;
        current = current->next;

        free(tmp);
    }

    free(stack);

    *s = NULL;
}
