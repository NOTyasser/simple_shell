#include "shell.h"

/**
 * _getenv - Function that gets the value of an environment variable.
 * @var: The name of the environment variable.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(char *var)
{
	int s;
	char *val, *lmp, *key, *dev;

	for (s = 0; environ[s]; s++)
	{
		lmp = _strdup(environ[s]);
		key = strtok(lmp, "=");
		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			dev = _strdup(val);
			free(lmp);
			return (dev);
		}
		free(lmp), lmp = NULL;

	}
	return (NULL);
}
