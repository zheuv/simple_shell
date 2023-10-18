#include "shell.h"




/**
 * main - The main function for a simple shell program
 *
 * Description: This program emulates a basic shell, accepting and executing
 * commands entered by the user.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *input = NULL, **args = NULL;
	size_t buf_size = 0;
	int exit_num = -1;

	while (1)
	{
		input = NULL;
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		else
		{
			free(input);
			perror("getline()");
			exit(EXIT_FAILURE);
		}
		read_the_input(&input, &buf_size);
		if (input[0] == '\0')
		{
			free(input);
			continue;
		}
		if (check_spaces_tabs(input))
		{
			free(input);
			continue;
		}
		args = tokenize_the_input(input);
		if (!validate_the_command(args, input, exit_num))
		{
			free(input);
			continue;
		}
		execute_the_forked_command(args, input);
		if (args != NULL)
		{
			free_arguments(args);
		}
		free(input);
	}
	return (0);
}

