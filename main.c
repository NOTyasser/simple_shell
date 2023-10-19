#include "shell.h"

/**
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
