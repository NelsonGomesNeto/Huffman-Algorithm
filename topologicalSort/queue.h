#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct queue_t queue_t;
typedef struct nodeQueue_t nodeQueue_t;

queue_t* newQueue();
nodeQueue_t* newNodeQueue(int value);

bool isQueueEmpty(queue_t* queue);

int front(queue_t* queue);
void enqueue(queue_t* queue, int value);

void dequeue(queue_t* queue);
void destroyQueue(queue_t* queue);
