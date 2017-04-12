#include "progressBar.h"

void updateProgress(double porcentage)
{
  system(CLEAR);
  printf("%.2lf%%\n", porcentage);
}
