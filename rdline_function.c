#include "shell.h"

char *rd_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nrd;

	nrd = getline(&line, &len, stdin);
	if (nrd == -1)
	{
		return (NULL);
	}

	return (line);
}
