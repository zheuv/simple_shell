#include "shell.h"

/**
 * validate_the_command - Validate and handle the user command
 * @args: An array of command arguments
 * @input: The user input string
 * @exit_num: The exit status to set on exit
 *
 * Description:
 * This function validates and handles the user command. It first checks if the
 * command is a built-in command and handles it if it is. If the command is not
 * a built-in, it checks whether the command exists in the system's
 * command does not exist, it displays an error message and frees
 * array.
 *
 * Return: 1 on success (command is valid), 0 on failure
 */
int validate_the_command(char **args, char *input, int exit_num)
{
	if (handle_the_builtins(args, input, exit_num))
	{
		return (1);
	}

	if (!does_command_exist(args))
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		free_arguments(args);
		return (0);
	}

	return (1);
}

