#ifndef LIST_H
#define LIST_H

typedef struct _list list_t;

list_t* createList();

void sortList(list_t *list);

list_t* listFromArray(int array[]);

void* createTreeFromList(list_t *list);

void printList(list_t *list);

#endif //LIST_H
