#include "shell.h"

/**
 * rd_line - Read a line of input from the user.
 *
 * Return: A pointer to the line read, or NULL on failure.
 */
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
