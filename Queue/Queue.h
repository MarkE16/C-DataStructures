#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>

struct Node {
    void *data;
    struct Node *next;
};

enum QueueType {
    STRING,
    INTEGER,
    CHARACTER
};

struct Queue {
  struct Node *head;
  struct Node *tail;
  enum QueueType type;
  int size;
};

struct Queue* createQueue(enum QueueType);
struct Node* peek(struct Queue*);
void append(struct Queue*, void*);
struct Node* pop(struct Queue*);
void printQueue(struct Queue*);
void freeQueue(struct Queue**);

#endif // QUEUE_H