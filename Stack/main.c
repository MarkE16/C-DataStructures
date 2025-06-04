#include "Stack.h"

int main() {
    struct Stack *intStack = createStack(INTEGER);

    int x = 42;
    int y = 100;
    push(intStack, &x);

    printStack(intStack);

    push(intStack, &y);

    printStack(intStack);

    int *top = (int*) peek(intStack);

    if (top == NULL) {
        printf("Integer does not exist.\n");
    } else {
        printf("Top value: %d\n", *top);
    }

    struct Node *topNode = pop(intStack);

    if (topNode == NULL) {
        printf("Top node does not exist.\n");
    } else {
        printf("Popped node: %d\n", *(int *)topNode->data);
        free(topNode);
    }
    
    top = peek(intStack);
    
    if (top == NULL) {
        printf("New top does not exist.\n");
    } else {
        printf("New top: %d", *top);
    }

    freeStack(&intStack);
    return 0;
}
