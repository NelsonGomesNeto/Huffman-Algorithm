#ifndef GRAPHPREPARE_H
#ifndef GRAPHPREPARE_H
#define GRAPHPREPARE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Function: putAbscissaInFile
 * ----------------------------
 *   Puts the R x axis in the given file
 *
 *   pFile: FILE* of the file to put the x axis
 *   itens: integer of the x range
 *   precision: integer of how many x jump
 *
 *   returns: nothing
 */
void putAbscissaInFile(FILE *pFile, int itens, int precision);

/*
 * Function: putRcomands
 * ----------------------------
 *   Puts the R commands in the file
 *
 *   pFile: FILE* of the file to put the R commands
 *   title: char array (string) of the title of the Rscript
 *   withLimits: boolean wheter the axis will have limit or nothing
 *   xlim: integer array of the range of the x axis
 *   ylim: integer array of the range of the y axis
 *
 *   returns: nothing
 */
void putRcomands(FILE *pFile, char title[], bool withLimits, int xlim[], int ylim[]);

/*
 * Function: generateGraph
 * ----------------------------
 *   Generates Rscript files with the structures benchmarks
 *
 *   size: integer of the number os elements to benchmark the structures
 *   precision: integer of how many x jump
 *
 *   returns: nothing
 */
void generateGraph(int size, int precision);

/*
 * Function: unifyGraphs
 * ----------------------------
 *   Unifies to graphs to a single Rscript
 *
 *   heap: FILE* of the file Rscripts to be unified
 *   priority: FILE* of the file Rscripts to be unified
 *   plotR: char array (string) of the name of the Rscript file to be created
 *   plotPDF: char array (string) of the desired name of the PDF
 *   plotTitle: char array (string) of the desired title of the PDF
 *   xlim: integer array of the range of the x axis
 *   ylim: integer array of the range of the y axis
 *
 *   returns: nothing
 */
void unifyGraphs(FILE *heap, FILE *priority, char plotR[], char plotPDF[], char plotTitle[], int xlim[], int ylim[]);

#endif //GRAPHPREPARE_H
