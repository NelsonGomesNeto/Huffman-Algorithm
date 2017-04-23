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

/*
 * Function: getHeader
 * ----------------------------
 *   pFile: FILE* of the file to get the header
 *
 *   returns: int* where position 0 holds the trash size and position 1 holds the tree size
 */
int* getHeader(FILE *pFile);

/*
 * Function: decompress
 * ----------------------------
 *   Decompresses a file
 *
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void decompress(char pathFile[]);

/*
 * Function: multipleDecompress
 * ----------------------------
 *   Decompresses a file multiple times
 *
 *   quantityString: char array (string) with how many decommpressions will be made
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void multipleDecompress(char quantityString[], char pathFile[]);

/*
 * Function: createDecompressedFileName
 * ----------------------------
 *   pathFile: char array (string) with the file path
 *
 *   returns: char* (string) of the decompressed file name
 */
char* createDecompressedFileName(char pathFile[]);

/*
 * Function: fixDecompressExtension
 * ----------------------------
 *   Fixes the decompressed file extension by replacing the .huff
 *
 *   pathFile: char array (string) with the file path
 *
 *   returns: nothing
 */
void fixDecompressExtension(char pathFile[]);

#endif //DECOMPRESSFILE_H
