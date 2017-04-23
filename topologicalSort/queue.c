#include "queue.h"

struct queue_t
{
  nodeQueue_t *head;
  nodeQueue_t *tail;
};

struct nodeQueue_t
{
  int value;
  nodeQueue_t *next;
};

queue_t* newQueue()
{
  queue_t *temp = malloc(1 * sizeof(queue_t));
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

nodeQueue_t* newNodeQueue(int value)
{
  nodeQueue_t *temp = malloc(1 * sizeof(nodeQueue_t));
  temp->value = value;
  temp->next = NULL;
  return(temp);
}

bool isQueueEmpty(queue_t* queue)
{
  return(queue->head == NULL);
}

int front(queue_t* queue)
{
  return(queue->head->value);
}

void enqueue(queue_t* queue, int value)
{
  nodeQueue_t *temp = newNodeQueue(value);
  if (isQueueEmpty(queue))
  {
    queue->head = temp;
    queue->tail = temp;
  }
  else
  {
    queue->tail->next = temp;
    queue->tail = temp;
  }
}

void dequeue(queue_t* queue)
{
  if (isQueueEmpty(queue)) return;
  nodeQueue_t *temp = queue->head;
  queue->head = queue->head->next;
  free(temp);
}

void destroyQueue(queue_t* queue)
{
  while (!isQueueEmpty(queue))
    dequeue(queue);

  free(queue);
}
