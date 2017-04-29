#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _Queue Queue_t;
typedef struct _NodeQueue NodeQueue_t;

Queue_t* newQueue();
NodeQueue_t* newNodeQueue(int value);

bool isQueueEmpty(Queue_t* queue);

int front(Queue_t* queue);
void enqueue(Queue_t* queue, int value);

void dequeue(Queue_t* queue);
void destroyQueue(Queue_t* queue);
