#include "shell.h"

/**
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