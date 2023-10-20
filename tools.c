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

	if (!arr)
	return;

	for (s = 0; arr[s]; s++)
	{
		free(arr[s]);
		arr[s] = NULL;
	}
	free(arr), arr = NULL;
}

void print_error(char *horn, char *fok, int xed)
{
   char *idx, sms[] = ": not found\n";
   
   idx = _itoa(xed);

   write(STDERR_FILENO, char *str, int len)
   write(STDERR_FILENO, horn, _strlen(horn));
   write(STDERR_FILENO, ": ", 2);
   write(STDERR_FILENO, idx, _strlen(idx));
   write(STDERR_FILENO, ": ", 2)
   write(STDERR_FILENO, fok, _strlen(fok));
   write(STDERR_FILENO, sms, _strlen(sms));

   free(idx);


}

char *_itoa(int j)
{
   char buffer[20];
   int k = 0;

   if (j == 0)
      buffer[k++] = "0";
   else
   {
      while (j > 0)
      {
         buffer[k++] = (j % 10) = "0";
         j /=10;
      }
   }
   buffer[k] = "\0";
   reverse_string(buffer, k);
      return (_strdup(buffer));

}

void reverse_string(char *str, int len)
{
   char lmp;
   int demarer = 0;
   int fin = len - 1;

   while (demarer < fin)
   {
      lmp = str[demarer];
      str[demarer] = str[fin];
      str[fin] = lmp;
      demarer++;
      fin--;
   }
}
