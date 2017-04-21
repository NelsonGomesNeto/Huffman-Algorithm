#include "heap.h"

struct _heap
{
  int size;
  int capacity;
  char heapType;
  int *data;
};

heap_t* createHeap(int capacity, char heapType)
{
  heap_t *temp = (heap_t*) malloc(1 * sizeof(heap_t));
  temp->size = 0;
  temp->capacity = capacity;
  temp->heapType = heapType;
  temp->data = (int*) malloc((capacity + 1) * sizeof(int));
  return(temp);
}

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

bool compareHeapWithType(int a, int b, char heapType)
{
  if (heapType == '+')
    return(a > b);
  else // (heapType == '-')
    return(a < b);
}

int enqueueHeap(heap_t *heap, int item)
{
  int compares = 1;
  if (heap->size >= heap->capacity)
    printf("Heap Overflow\n");
  else
  {
    heap->data[++ heap->size] = item;

    int keyIndex = heap->size;
    int parentIndex = getParentIndex(heap, heap->size);

    while ((compares ++) && parentIndex >= 1 && compareHeapWithType(heap->data[keyIndex], heap->data[parentIndex], heap->heapType))
    {
      swap(&heap->data[keyIndex], &heap->data[parentIndex]);

      keyIndex = parentIndex;
      parentIndex = getParentIndex(heap, keyIndex);
    }
  }
  return(compares);
}

int dequeueHeap(heap_t *heap)
{
  int compares = 1;
  if (isHeapEmpty(heap))
  {
    printf("Heap underflow\n");
    return(compares);
  }
  else
  {
    //int item = heap->data[1];

    heap->data[1] = heap->data[heap->size];
    heap->size --;

    heapify(heap, 1, &compares);
    return(compares);
  }
}

int getParentIndex(heap_t *heap, int i)
{
  return(i >> 1); // Dividido por 2
}

int getLeftIndex(heap_t *heap, int i)
{
  return(i << 1); // Multiplicado por 2
}

int getRightIndex(heap_t *heap, int i)
{
  return((i << 1) + 1); // Multiplicado por 2 e added 1
}

int frontHeap(heap_t *heap)
{
  if (isHeapEmpty(heap)) return(INT_MIN);

  return(heap->data[1]);
}

bool isHeapEmpty(heap_t *heap)
{
  return(!heap->size);
}

void heapify(heap_t *heap, int i, int *compares)
{
  (*compares) ++;

  int largest;
  int leftIndex = getLeftIndex(heap, i);
  int rightIndex = getRightIndex(heap, i);

  if (leftIndex <= heap->size && compareHeapWithType(heap->data[leftIndex], heap->data[i], heap->heapType))
    largest = leftIndex;
  else
    largest = i;

  if (rightIndex <= heap->size && compareHeapWithType(heap->data[rightIndex], heap->data[largest], heap->heapType))
    largest = rightIndex;

  if (heap->data[i] != heap->data[largest])
  {
    swap(&heap->data[i], &heap->data[largest]);
    heapify(heap, largest, &(*compares));
  }
}

int itemOf(heap_t *heap, int i)
{
  return(heap->data[i]);
}

void heapSort(heap_t *heap)
{
  int i, trash = 0;
  for (i = heap->size; i >= 2; i --)
  {
    swap(&heap->data[1], &heap->data[i]);

    heap->size --;
    heapify(heap, 1, &trash);
  }
}

void destroyHeap(heap_t *heap)
{
  free(heap->data);
  free(heap);
}
