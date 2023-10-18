#include "shell.h"

/**
 * handle_the_builtins - Handle built-in shell commands
 * @args: An array of command arguments
 * @input: The user input string
 * @exit_num: The exit status to set on exit
 *
 * Description:
 * This function handles built-in shell commands like "exit" and "env". If the
 * command is "exit," it checks for an optional exit status, sets it, frees
 * memory, and exits the program. If the command is "env," it prints the
 * environment variables and returns. For all other commands, it returns 0.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */
int handle_the_builtins(char **args, char *input, int exit_num)
{
	char **env;
	int exit_status = EXIT_SUCCESS;

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			exit_status = atoi(args[1]);
		else if (exit_num != -1)
			exit_status = exit_num;
		free_arguments(args);
		free(input);
		exit(exit_status);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (env = environ; *env; ++env)
			printf("%s\n", *env);
		free_arguments(args);
		return (1);
	}

	return (0);
}

