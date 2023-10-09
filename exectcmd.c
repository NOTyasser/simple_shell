#include "shell.h"

/**
 * executecmd - Execute a command with specified arguments
 * @cmd: An array of strings representing the command and its arguments
 * @ar: An array of strings representing the command-line arguments
 * @env: An array of strings representing the environment variable
 * @tok: A pointer to an integer representing the number of tokens
 * @l: A pointer to an integer representing the current line number
 * @ex: A pointer to an integer representing the exit status
 *
 * Return: The result of executing the command
 */

int executecmd(char **cmd, char **ar, char **env, int *tok, int *l, int *ex)
{
	int cd = -2;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		exit_(cmd, *l);
		return (1);
	}
	if (_strcmp(cmd[0], "clear") == 0)
	{
		_print_str("\033[H\033[J");
	}
	if (_strcmp(cmd[0], "mkdir") == 0)
	{
		if (mkdir(cmd[1], 0777) == -1)
			perror(cmd[0]);
		cd = 1;
	}
	cd = handle_commanets(cmd, ex);

	if (_strcmp(cmd[0], "cd") == 0)
	{
		if (cd_command(*tok, cmd))
		{
			cd = -1;
		}
		else
		{
			cd = 0;
		}
	}
	return (executCMD(cmd, ar, env, tok, cd));
}

/**
 * get_Home_Dir - Retrieve home directory of current user
 * Return: A pointer to a string represent the user's home directory, or
 * NULL if the home directory isn't found or error occurs
 */

char *get_Home_Dir(void)
{
	const char *directory_path = "/home";
	DIR *dir;
	struct dirent *entry;

	char *homedir = NULL;

	dir = opendir(directory_path);
	if (dir == NULL)
	{
		return (homedir);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_DIR)
		{
			if (_strcmp(entry->d_name, ".") != 0 && _strcmp(entry->d_name, "..") != 0)
			{
				homedir = entry->d_name;
			}
		}
	}

	closedir(dir);
	return (homedir);
}

/**
 * Home_navigate - Navigation to home directory of the user
 * Return: if successfully navigat to home directory return 1, 0 otherwise.
 */

int Home_navigate(void)
{
	const char *home_dir = my_getenv("HOME");

	if (!home_dir)
	{
		home_dir = my_getenv("PWD");
		if (!home_dir)
		{
			return (0);
		}
	}

	if (chdir(home_dir) != 0)
	{
		return (0);
	}
	return (1);
}

#include "shell.h"

int tokenizer(char **line, int *tokens, char **commands,
		char **argv, char **env, int *l, int *exi, int *status)
{
	char *token = NULL, *temp = NULL, *lin = _strdup(*line);
	int cpt = 0, i = 0, chek = chech_semicolon(*line);

	if (!*line || !*line[0] || _strcmp(*line, "\n") == 0)
	{
		*tokens = 0;
		return (0);
	}
	temp = _strdup(*line);
	token = strtok(temp, DELIMITERS);
	while (token)
	{
		if ((_strcmp(token, "#") == 0 && i != 0) || _strcmp(token, "||") == 0)
			break;
		cpt++;
		token = strtok(NULL, DELIMITERS);
	}
	*tokens = cpt;
	commands = (char **)malloc(sizeof(char *) * (cpt + 1));
	token = strtok(*line, DELIMITERS);
	while (token)
	{
		if ((_strcmp(token, "#") == 0 && i != 0) || _strcmp(token, "||") == 0)
			break;
		commands[i] = _strdup(token);
		token = strtok(NULL, DELIMITERS);
		i++;
	}
	free(temp), free(*line);
	*line = NULL;
	commands[i] = NULL;
	if (!chek)
	{
		free(lin);
		*status = executecmd(commands, argv, env, tokens, l, exi);
	}
	else
		*status = semicolon_handler(commands, argv, env, tokens, l, exi, lin);
	return (*status);
}
