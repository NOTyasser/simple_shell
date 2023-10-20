#include "shell.h"

/**
 * stringarrayfree - Frees a string array.
 *
 * @arr: The string array to be freed.
 * Return : (void)
 */
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
