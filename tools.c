#include "shell.h"

void stringarrayfree(char **arr)
{
    int s;
    if(!arr)
       return;

    for (s = 0; command[s]; s++)
         {
            free(arr[s]);
            arr[s] = NULL;
         }
         free(arr), arr = NULL;
}



        