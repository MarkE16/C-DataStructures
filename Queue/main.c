#include "Queue.h"

int main() {
    struct Queue *intQueue = createQueue(INTEGER);

    int x = 42;
    int y = 100;

    append(intQueue, &x);
    append(intQueue, &y);

    printQueue(intQueue);

    int *front = (int*) peek(intQueue);

    if (front == NULL) {
        printf("Front does not exist.\n");
    } else {
        printf("Front value: %d\n", *front);
    }

    struct Node *poppedFront = pop(intQueue);

    if (front == NULL) {
        printf("Front does not exist.\n");
    } else {
        printf("popped front: %d\n", *(int*)poppedFront->data);
        free(poppedFront);
    }

    printQueue(intQueue);

    poppedFront = pop(intQueue);

    if (front == NULL) {
        printf("Front does not exist.\n");
    } else {
        printf("popped front: %d\n", *(int*)poppedFront->data);
        free(poppedFront);
    }

    printQueue(intQueue);

    freeQueue(&intQueue);
    return 0;
}
