#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <inttypes.h>

typedef struct _huffTree huffTree_t;

huffTree_t* createNode(unsigned char byte, long long int frequency);
huffTree_t* createTree(unsigned char byte, long long int frequency, huffTree_t *left, huffTree_t *right);

void createTreeFromPreFix(huffTree_t **newTree, int end, int *i);

bool isHuffTreeEmpty(huffTree_t *hm);

bool isMoreFrequent(huffTree_t *a, huffTree_t *b);
void swap(huffTree_t *a, huffTree_t *b);

void addNext(huffTree_t *atual, huffTree_t *prox);
huffTree_t* getNext(huffTree_t *atual);
void setNext(huffTree_t *atual, huffTree_t *next);
long long int getFrequency(huffTree_t *atual);

void printNode(huffTree_t *atual);
void printTreeInFile(FILE *newFile, huffTree_t *tree);
void printTreePreOrder(huffTree_t *tree);
void printTreeInOrder(huffTree_t *tree);
void printTreePosOrder(huffTree_t *tree);

void createDictionary(huffTree_t *tree, unsigned char dictionary[][2], long long int frequency[], unsigned char bits, int depth);

int countTrashSize(unsigned char dictionary[][2], long long int frequency[]);
int countTreeSize(huffTree_t *tree);

#endif //HUFFTREE_H
