#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef struct _heap heap_t;

heap_t* createHeap(int capacity, char heapType);

int enqueueHeap(heap_t *heap, int item);

int getParentIndex(heap_t *heap, int i);
int getLeftIndex(heap_t *heap, int i);
int getRightIndex(heap_t *heap, int i);
int frontHeap(heap_t *heap);
bool isHeapEmpty(heap_t *heap);

void heapify(heap_t *heap, int i, int *compares);

int itemOf(heap_t *heap, int i);

void heapSort(heap_t *heap);

int dequeueHeap(heap_t *heap);
void destroyHeap(heap_t *heap);

void generateGraphHeap(int size, int precision);

#endif //HEAP_H
