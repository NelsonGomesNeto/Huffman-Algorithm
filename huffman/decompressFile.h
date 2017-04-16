#ifndef DECOMPRESSFILE_H
#define DECOMPRESSFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "huffTree.h"
#include "list.h"
#include "binaryOperations.h"
#include "progressBar.h"

int* getHeader(FILE *pFile);

void decompress(char pathFile[]);

void multipleDecompress(char quantityString[], char pathFile[]);

char* createDecompressedFileName(char pathFile[]);

void fixExtension2(char pathFile[]);

#endif //DECOMPRESSFILE_H
