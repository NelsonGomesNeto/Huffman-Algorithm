#ifndef LIST_H
#define LIST_H

typedef struct _list list_t;

list_t* createList();

void addNode(list_t *list, void *newNode /*huffTree_t*/);
void addTreeSorted(list_t *list, void *newTree /*huffTree_t*/);

void sortList(list_t *list);

list_t* listFromArray(long long int array[]);

void* createTreeFromList(list_t *list);

void printList(list_t *list);

#endif //LIST_H
