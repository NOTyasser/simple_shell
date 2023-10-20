#include "shell.h"

/**
 * _execute - Function to execute a command with fork and execve
 * @command: An array of strings representing the command and its arguments
 * @argv: The name of the program
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **argv)
{
	pid_t bro;
	int status;

	bro = fork();
	if (bro == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			stringarrayfree(command);
			exit(0);
		}

	}
	else
	{
		waitpid(bro, &status, 0);
		stringarrayfree(command);
	}
	return (WEXITSTATUS(status));
}
