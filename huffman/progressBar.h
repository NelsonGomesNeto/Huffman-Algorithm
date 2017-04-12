#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
#include <stdio.h>
#include <stdlib.h>

//And in the point you want to clear the screen:
//....
void updateProgress(double porcentage);
//....

#endif //PROGRESSBAR_H
