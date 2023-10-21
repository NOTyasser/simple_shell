#include "shell.h"

/**
 * _getpath - Find the full path of an executable in the PATH variable.
 * @direct: The name of the executable.
 *
 * Return: A dynamically allocated string containing the full path of the
 * executable, or NULL if not found.
 */
char *_getpath(char *direct)
{
	int s;
	char *dev_path, *new_cmd, *directory;
	struct stat rw;

	for (s = 0; direct[s]; s++)
	{
		if (direct[s] == '/')
		{
			if (stat(direct, &rw) == 0)
				return (_strdup(direct));
			return (NULL);

		}
	}

	dev_path = _getenv("PATH");
	if (!dev_path)
		return (NULL);

	directory = strtok(dev_path, ":");
	while (directory)
	{
		new_cmd = malloc(_strlen(directory) + _strlen(direct) + 2);
		if (new_cmd)
		{
			_strcpy(new_cmd, directory);
			_strcat(new_cmd, "/");
			_strcat(new_cmd, direct);
			if (stat(new_cmd, &rw) == 0)
			{
				free(dev_path);
				return (new_cmd);
			}
			free(new_cmd), new_cmd = NULL;

			directory = strtok(NULL, ":");
		}
	}
	free(dev_path);
	return (NULL);
}
