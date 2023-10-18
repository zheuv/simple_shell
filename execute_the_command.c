#include "shell.h"

/**
 * execute_the_command - Execute a command with arguments
 * @args: An array of command arguments
 * @input: The user input string
 *
 * Description:
 * This function attempts to execute a command specified in the 'args' array.
 * If the command's path is not provided and the command is not in the current
 * directory, it searches for the command in the directories specified in the
 * PATH environment variable. If it finds a valid executable, it executes it.
 * If the command execution fails, it prints an error message and returns
 * EXIT_FAILURE. If the command is executed successfully, it does not return.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on failure.
 */
int execute_the_command(char **args, char *input)
{
	char *path, *dir;
	char path_search[4096];
	char command_path[4096];

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		execve(args[0], args, NULL);
		perror(input);
		return (EXIT_FAILURE);
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
		{
			write(2, "PATH variable not found.\n", 25);
			exit(EXIT_FAILURE);
		}
		sprintf(path_search, ":%s:/usr/bin", path);
		dir = strtok(path_search, ":");
		while (dir)
		{
			snprintf(command_path, sizeof(command_path), "%s/%s", dir, args[0]);
			if (access(command_path, X_OK) == 0)
			{
				execve(command_path, args, NULL);
				perror(input);
				return (EXIT_FAILURE);
			}
			dir = strtok(NULL, ":");
		}
	}
	return (EXIT_SUCCESS);
}

