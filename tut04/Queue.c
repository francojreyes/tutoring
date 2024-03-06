#include <stdlib.h>

#include "Stack.h"

typedef struct queue *Queue;

struct queue {
    Stack s1;
    Stack s2;
};

Queue QueueNew(void) {
    Queue q = malloc(sizeof(struct queue));
    q->s1 = StackNew();
    q->s2 = StackNew();
    return q;
}

void QueueEnqueue(Queue q, int item) {
    // TODO
}

int QueueDequeue(Queue q) {
    // TODO
    return 0;
}
