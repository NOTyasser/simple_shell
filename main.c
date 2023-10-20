#include "shell.h"

/**
<<<<<<< HEAD
 * main - main function of simple shell
 * @ac : Arguments's count
 * @argv : Arguments
 * Return : Always 0 (success)
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status;
	(void) ac;

	while (1)
	{
		line = rd_line();
		command = tokenizer(line);
		status = _execute(command, argv);
	}
}
=======
 * main - main fuction of simple shell
 * @ac : Arguments's count
 * @av : Arguments
 * Return : Always 0 (success)
*/

int main(int ac, char **argv)
{
    char *line = NULL;
    char **command = NULL;
    int status = 0;
    (void) ac;

    while (1);
    {
        line = rd_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 1);
            return (status);
        }


        command = tokenizer(line);
        if (!command)
         continue;


         
        status = _execute(command, argv);

        
    }
}
>>>>>>> 3372b990fe4337bc0dc8a166c184e4c1c2ec3537
