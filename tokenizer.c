#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of strings.
 *
 * @line: The input string to be tokenized.
 *
 * Return: A dynamically allocated array of strings, or NULL on failure.
 */
char **tokenizer(char *line)
{
    char *token = NULL;
    char *lmp = NULL;
    char **command = NULL;
    int cpt = 0, i = 0;

    if (!line)
    return (NULL);
    lmp = _strdup(line);
    token = strtok(lmp, DELIMITERS);
    if (token = NULL)
    {
        free(line), line = NULL;
        free(lmp), lmp = NULL;
        return (NULL);
    }
    while (token)
    {
        cpt++;
        token = strtok(NULL, DELILITERS);
    }
    free(lmp), lmp = NULL;

    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }
    token = strtok(line, DELIMITERS);
    while (token)
    {
        command[i] = _strdup(token);
        token = strtok(NULL, DELILITERS);
        i++;
    }
    free(line), line = NULL;
    command[i] = NULL;
    return (command);


}
