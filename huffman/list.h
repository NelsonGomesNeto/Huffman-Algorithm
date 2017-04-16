#ifndef LIST_H
#define LIST_H
#include "huffTree.h"

typedef struct _list list_t;

list_t* createList();
list_t* createListFromArray(long long int array[]);

void addNode(list_t *list, void *newNode /*huffTree_t*/);
void addTreeSorted(list_t *list, void *newTree /*huffTree_t*/);

void sortList(list_t *list);

void* createTreeFromList(list_t *list);

void printList(list_t *list);

void destroyList(list_t *list);

#endif //LIST_H
