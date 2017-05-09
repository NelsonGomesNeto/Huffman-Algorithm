#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

/*
 * typedef of a priority queue struct: PriorityQueue_t
 * ----------------------------
 */
typedef struct _PriorityQueue PriorityQueue_t;

/*
 * typedef of a Node struct: Node_t
 * ----------------------------
 */
typedef struct _Node Node_t;

/*
 * Function: newPriorityQueue
 * ----------------------------
 *
 *   returns: PriorityQueue_t* of the created Queue.
 */
PriorityQueue_t* newPriorityQueue();

/*
 * Function: newNode
 * ----------------------------
 *
 *   returns: Node_t* of the created Node.
 */
Node_t* newNode(int value, int priority);

/*
 * Function: isPriorityQueueEmpty
 * ----------------------------
 *
 *   pq: PriorityQueue_t* to check
 *
 *   returns: True wheter is Empty, False wheter not.
 */
bool isPriorityQueueEmpty(PriorityQueue_t *pq);

/*
 * Function: front
 * ----------------------------
 *
 *   pq: PriorityQueue_t* to get
 *
 *   returns: Node_t* of the front Node.
 */
Node_t* front(PriorityQueue_t *pq);

/*
 * Function: maximum
 * ----------------------------
 *
 *   pq: PriorityQueue_t* to get maximum number
 *
 *   returns: An integer of the front node.
 */
int maximum(PriorityQueue_t *pq);

/*
 * Function: printPriorityQueue
 * ----------------------------
 *
 *   pq: PriorityQueue_t* to get maximum number.
 *   mode: char to define mode will separate each node while printing.
 *
 *   returns: Nothing.
 *   */
void printPriorityQueue(PriorityQueue_t *pq, char mode);

/*
 * Function: enqueuePriorityQueue
 * ----------------------------
 *
 *   value: integer to enqueue.
 *   priority: integer which represents the priority.
 *
 *   returns: Integer which represents the number of comparisons.
 *   */
int enqueuePriorityQueue(PriorityQueue_t *pq, int value, int priority);

/*
 * Function: dequeuePriorityQueue
 * ----------------------------
 *
 *   pq: PriorityQueue_t* to dequeue.
 *
 *   returns: Integer which represents the number of comparisons.
 *   */
int dequeuePriorityQueue(PriorityQueue_t *pq);

/*
 * Function: destroyPriorityQueue
 * ----------------------------
 *
 *   pq: PriorityQueue_t* free memory.
 *
 *   returns: nothing.
 *   */
void destroyPriorityQueue(PriorityQueue_t *pq);

#endif //PRIORITYQUEUE_H
