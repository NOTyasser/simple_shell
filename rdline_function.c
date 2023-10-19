#include "shell.h"

char *rd_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nrd;

    if (isatty(STDIN_FILENO))
    write(STDOUT_FILENO, "$ ", 2);
    nrd = getline(&line, &len, stdin);
    if (nrd == -1)
    {
        free(line);
        return (NULL);
    }



    return (line);
}