#include "priorityQueue.h"

struct priorityQueue_t
{
  node_t *head;
};

struct node_t
{
  int value;
  int priority;
  node_t *next;
};

priorityQueue_t* newPriorityQueue()
{
  priorityQueue_t *temp = malloc(1 * sizeof(priorityQueue_t));
  temp->head = NULL;
  return(temp);
}

node_t* newNode(int value, int priority)
{
  node_t *temp = malloc(1 * sizeof(node_t));
  temp->value = value;
  temp->priority = priority;
  temp->next = NULL;
  return(temp);
}

bool isPriorityQueueEmpty(priorityQueue_t *pq)
{
  return(pq->head == NULL);
}

node_t* front(priorityQueue_t *pq)
{
  if (isPriorityQueueEmpty(pq)) return(NULL);

  return(pq->head);
}

int maximum(priorityQueue_t *pq)
{
  if (isPriorityQueueEmpty(pq)) return(INT_MIN);

  return(pq->head->value);
}

void printPriorityQueue(priorityQueue_t *pq, char mode)
{
  if (isPriorityQueueEmpty(pq)) return;

  node_t *curr = pq->head;
  while (curr->next != NULL)
  {
    printf("%d%c", curr->value, mode);
    curr = curr->next;
  } printf("%d\n", curr->value);
}

int enqueuePriorityQueue(priorityQueue_t *pq, int value, int priority)
{
  node_t *temp = newNode(value, priority);
  int compares = 1;
  if (isPriorityQueueEmpty(pq) || temp->priority > pq->head->priority)
  {
    temp->next = pq->head;
    pq->head = temp;
  }
  else
  {
    node_t *curr = pq->head;
    while ((compares ++) && curr->next != NULL && temp->priority < curr->next->priority)
      curr = curr->next;

    temp->next = curr->next;
    curr->next = temp;
  }
  return(compares);
}

int dequeuePriorityQueue(priorityQueue_t *pq)
{
  if (isPriorityQueueEmpty(pq)) return(1);

  node_t *temp = pq->head;
  pq->head = pq->head->next;
  free(temp);

  return(1);
}

void destroyPriorityQueue(priorityQueue_t *pq)
{
  while (!isPriorityQueueEmpty(pq))
    dequeuePriorityQueue(pq);

  free(pq);
}
