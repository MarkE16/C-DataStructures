#include "Queue.h"

void printNode(enum QueueType type, void *d) {
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

/**
 * Create a Queue.
 */
struct Queue* createQueue(enum QueueType type) {
    struct Queue *ptr = (struct Queue*) malloc(sizeof(struct Queue));

    ptr->head = ptr->tail = NULL;
    ptr->size = 0;
    ptr->type = type;

    return ptr;
}


/**
 * Get the element at the front of the queue.
 */
struct Node* peek(struct Queue* q) {
    return q->head;
}

/**
 * Add a value to the end of the queue.
 */
void append(struct Queue *q, void *d) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = d;
    n->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    q->size++;
}

struct Node* pop(struct Queue *q) {
    if (q->head == NULL) {
        return NULL;
    }
    
    struct Node *node = q->head;
    q->head = q->head->next;
    q->size--;
    
    if (q->head == NULL) {
        q->tail = NULL;
    }
    
    return node;
}

void printQueue(struct Queue *q) {
    struct Node *current = q->head;
    
    while (current != NULL) {
        printNode(q->type, current->data);
        current = current->next;
    }
}

void freeQueue(struct Queue **q) {
    struct Queue *queue = *q;
    
    struct Node *current = queue->head;
    
    while (current != NULL) {
        struct Node *tmp = current;
        current = current->next;
        
        free(tmp);
    }
    
    free(queue);
    
    // Prevent use-after-free
    *q = NULL;
}
