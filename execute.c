#include "shell.h"

/**
 * _execute - Function to execute a command with fork and execve
 * @command: An array of strings representing the command and its arguments
 * @argv: The name of the program
 * @xed: The exit code or error code
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **argv, int xed)
{
	char *new_cmd;
	pid_t bro;
	int status;

	new_cmd = _getpath(command[0]);
	if (!new_cmd)
	{
		print_error(argv[0], command[0], xed);
		stringarrayfree(command);
			return (127);

	}




	bro = fork();
	if (bro == 0)
	{
		if (execve(new_cmd, command, environ) == -1)
		{
			free(new_cmd), new_cmd = NULL;
			stringarrayfree(command);
		}

	}
	else
	{
		waitpid(bro, &status, 0);
		stringarrayfree(command);
		free(new_cmd), new_cmd = NULL;

	}
	return (WEXITSTATUS(status));
}
