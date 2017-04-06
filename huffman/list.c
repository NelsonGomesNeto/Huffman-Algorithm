#include "list.h"
#include "huffTree.h"

struct _list
{
  int size;
  huffTree_t *head;
  huffTree_t *tail;
};

list_t* createList()
{
  list_t *temp = (list_t*) malloc(1 * sizeof(list_t));
  temp->size = 0;
  temp->head = NULL;
  temp->tail = NULL;
  return(temp);
}

void sortList(list_t *list)
{
  if (list->size <= 1) return;

  huffTree_t* o = list->head, *b;
  while (o != NULL)
  {
    b = getNext(o);
    while (b != NULL)
    {
      if (isMoreFrequent(o, b))
      {
        swap(o, b);
        //printf("Is it?\n");
      }

      b = getNext(b);
    }
    o = getNext(o);
  }
}

void addNode(list_t *list, huffTree_t *hm)
{
  if (list->size == 0)
  {
    list->head = hm;
    list->tail = hm;
  }
  else
  {
    addNext(list->tail, hm);
    list->tail = hm;
  }
  list->size ++;
}

list_t* listFromArray(int array[])
{
  printf("Creating\n");
  list_t *list = createList();
  int i;
  for (i = 0; i < 256; i ++)
  {
    if (array[i] != 0)
    {
      huffTree_t *temp;
      if (i == '*')
        temp = createNode('\e', array[i]);
      else
        temp = createNode(i, array[i]);

      addNode(list, temp);
      // printf("%c ~~ %d\n", i, array[i]);
    }
  }
  return(list);
}

void* createTreeFromList(list_t *list)
{
  huffTree_t *curr = list->head;
  while (list->size > 1)
  {

    curr = getNext(curr);
  }
}

void printList(list_t *list)
{
  huffTree_t *curr = list->head;
  while (!isHuffTreeEmpty(curr))
  {
    printNode(curr);
    curr = getNext(curr);
  }
}
