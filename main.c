#include "shell.h"

/**
 * main - Entry point for a simple shell program
 * @ac: The number of command line arguments
 * @argv: An array of command line arguments
 *
 * Return: The exit status of the shell.
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	(void) ac;

	while (1)
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
