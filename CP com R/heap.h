#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

/*
 * typedef of a heap struct: Heap_t
 * ----------------------------
 */
typedef struct _Heap Heap_t;

/*
 * Function: createHeap
 * ----------------------------
 *   capacity: integer of max capacity
 *   heapType: char with the heap type
 *
 *   returns: Heap_t* of the created Heap.
 */
Heap_t* createHeap(int capacity, char heapType);

/*
 * Function: enqueueHeap
 * ----------------------------
 *   heap: Heap_t* to enqued
 *   item: integer to enqueue in the Heap 
 *
 *   returns: an integer number of comparisons
 */
int enqueueHeap(Heap_t *heap, int item);

/*
 * Function: getParentIndex
 * ----------------------------
 *   heap: Heap_t* to get parent
 *   i: integer to get index 
 *
 *   returns: an integer number the parent
 */
int getParentIndex(Heap_t *heap, int i);

/*
 * Function: getLeftIndex
 * ----------------------------
 *   heap: Heap_t* to get parent
 *   i: integer to get index 
 *
 *   returns: an integer number of the left index
 */
int getLeftIndex(Heap_t *heap, int i);

/*
 * Function: getRightIndex
 * ----------------------------
 *   heap: Heap_t* to get parent
 *   i: integer to get index 
 *
 *   returns: an integer number of the right index
 */
int getRightIndex(Heap_t *heap, int i);

/*
 * Function: frontHeap
 * ----------------------------
 *   heap: Heap_t* to get front
 *
 *   returns: an integer from front
 */
int frontHeap(Heap_t *heap);

/*
 * Function: isHeapEmpty
 * ----------------------------
 *   heap: Heap_t* to check
 *
 *   returns: true wheter empty, false wheter not
 */
bool isHeapEmpty(Heap_t *heap);

/*
 * Function: heapify
 * ----------------------------
 *   heap: Heap_t* to do heapify
 *   i: integer where start the heapify
 *   compares:integer number of compares
 *   
 *   returns: nothing
 */
void heapify(Heap_t *heap, int i, int *compares);

/*
 * Function: itemOf
 * ----------------------------
 *   heap: Heap_t* to get 
 *   i: integer index want to get
 *   
 *   returns: integer of the item
 */
int itemOf(Heap_t *heap, int i);

/*
 * Function: heapSort
 * ----------------------------
 *   heap: Heap_t* to sort
 *   
 *   returns: nothing
 */
void heapSort(Heap_t *heap);

/*
 * Function: dequeueHeap
 * ----------------------------
 *   heap: Heap_t* to dequeue 
 *   
 *   returns: nothing
 */
int dequeueHeap(Heap_t *heap);

/*
 * Function: destroyHeap
 * ----------------------------
 *   heap: Heap_t* to free memory 
 *   
 *   returns: nothing
 */
void destroyHeap(Heap_t *heap);

#endif //HEAP_H
