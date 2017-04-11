#ifndef COMPRESSFILE_H
#define COMPRESSFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "huffTree.h"
#include "list.h"
#include "binaryOperations.h"

unsigned char* createHeader(int trashSize, int treeSize, huffTree_t *tree);

void compress();

void compressFile(FILE *pFile, unsigned char *header, bool dictionary[][256], int bitsQuantity[], huffTree_t *tree);

#endif //COMPRESSFILE_H
