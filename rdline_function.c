#include "shell.h"

char *rd_line(void)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 3372b990fe4337bc0dc8a166c184e4c1c2ec3537
