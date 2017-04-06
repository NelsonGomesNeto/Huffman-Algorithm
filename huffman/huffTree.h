#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _huffTree huffTree_t;

huffTree_t* createNode(unsigned char byte, int frequency);

//void makeTree()

bool isHuffTreeEmpty(huffTree_t *hm);

bool isMoreFrequent(huffTree_t *a, huffTree_t *b);
void swap(huffTree_t *a, huffTree_t *b);

void addNext(huffTree_t *atual, huffTree_t *prox);
huffTree_t* getNext(huffTree_t *atual);
void printNode(huffTree_t *atual);

#endif //HUFFTREE_H
