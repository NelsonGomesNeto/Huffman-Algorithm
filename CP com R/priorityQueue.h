#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef struct priorityQueue_t priorityQueue_t;
typedef struct node_t node_t;

priorityQueue_t* newPriorityQueue();
node_t* newNode(int value, int priority);

bool isPriorityQueueEmpty(priorityQueue_t *pq);

node_t* front(priorityQueue_t *pq);
int maximum(priorityQueue_t *pq);
void printPriorityQueue(priorityQueue_t *pq, char mode);
int enqueuePriorityQueue(priorityQueue_t *pq, int value, int priority);

int dequeuePriorityQueue(priorityQueue_t *pq);
void destroyPriorityQueue(priorityQueue_t *pq);

void generateGraphPriorityQueue(int size, int precision);

#endif //PRIORITYQUEUE_H
