#ifndef LIST_H
#define LIST_H
#include "huffTree.h"

/*
 * typedef of a list of huffman trees struct: list_t
 * ----------------------------
 */
typedef struct _list list_t;

/*
 * Function: createList
 * ----------------------------
 *   returns: list_t* of a list
 */
list_t* createList();

/*
 * Function: createListFromArray
 * ----------------------------
 *   array: long long integer array to create a list of
 *
 *   returns: list_t* of a list from a array
 */
list_t* createListFromArray(long long int array[]);

/*
 * Function: addNode
 * ----------------------------
 *   Adds a node to a list
 *
 *   list: list_t* list to have a node added
 *   newNode: void* of the node to add
 *
 *   returns: nothing
 */
void addNode(list_t *list, void *newNode /*huffTree_t*/);

/*
 * Function: addTreeSorted
 * ----------------------------
 *   Adds a tree to a list in a sorted way
 *
 *   list: list_t* list to have a node added
 *   newNode: void* of the node to add
 *
 *   returns: nothing
 */
void addTreeSorted(list_t *list, void *newTree /*huffTree_t*/);

/*
 * Function: addTreeSorted
 * ----------------------------
 *   Sorts a list according to the frequency each node's char (byte) occurs
 *
 *   list: list_t* list to sort
 *
 *   returns: nothing
 */
void sortList(list_t *list);

/*
 * Function: addTreeSorted
 * ----------------------------
 *   list: list_t* list to create a tree with
 *
 *   returns: void* of a huffman tree
 */
void* createTreeFromList(list_t *list);

/*
 * Function: addTreeSorted
 * ----------------------------
 *   Prints a list with printNode function
 *
 *   list: list_t* list to print
 *
 *   returns: nothing
 */
void printList(list_t *list);

/*
 * Function: destroyList
 * ----------------------------
 *   Destroys a list
 *
 *   list: list_t* list to destroy
 *
 *   returns: nothing
 */
void destroyList(list_t *list);

#endif //LIST_H
