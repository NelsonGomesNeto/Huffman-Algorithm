#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//And in the point you want to clear the screen:
//....
void updateProgress(char string[], int porcentage, bool cleaning);
//....
long long int* createProgressBar(FILE *pFile);

#endif //PROGRESSBAR_H
