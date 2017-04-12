#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

typedef struct _huffTree huffTree_t;

huffTree_t* createNode(unsigned char byte, long long int frequency);
huffTree_t* createTree(unsigned char byte, long long int frequency, huffTree_t *left, huffTree_t *right);
void createTreeFromPreFix(FILE *pFile, huffTree_t **newTree, int end, int *i);
huffTree_t* createTreeFromFile(char pathFile[]);

bool isHuffTreeEmpty(huffTree_t *hm);
int height(huffTree_t *hm);

bool isMoreFrequent(huffTree_t *a, huffTree_t *b);
void swap(huffTree_t *a, huffTree_t *b);

huffTree_t* getNext(huffTree_t *atual);
void setNext(huffTree_t *atual, huffTree_t *next);
long long int getFrequency(huffTree_t *atual);

void printNode(huffTree_t *atual);
void printTreeInFile(FILE *newFile, huffTree_t *tree);
void printTreePreOrder(huffTree_t *tree);
void printTreeInOrder(huffTree_t *tree);
void printTreePosOrder(huffTree_t *tree);

void createDictionary(huffTree_t *tree, bool dictionary[][256], int bitsQuantity[], long long int frequency[], bool bits[], int depth);

int countTrashSize(int bitsQuantity[], long long int frequency[]);
int countTreeSize(huffTree_t *tree);

void decompressBytes(FILE *pFile, FILE *newFile, huffTree_t *tree, int trashSize);

#endif //HUFFTREE_H
