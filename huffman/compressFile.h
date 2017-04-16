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
#include "progressBar.h"

// Receives the trash size, the tree size
// Returns the header in a size two array of unsigned char
unsigned char* createHeader(int trashSize, int treeSize);

void compress(char pathFile[]);

void multipleCompress(char quantityString[], char pathFile[]);

void compressFile(char pathFile[], unsigned char *header, bool dictionary[][256], int bitsQuantity[], huffTree_t *tree);

char* createCompressedFileName(char pathFile[]);

void fixExtension(char pathFile[]);

#endif //COMPRESSFILE_H
