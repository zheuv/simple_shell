#include "shell.h"

/**
 * tokenize_the_input - Tokenize an input string into an array of arguments
 * @input: The user input string to tokenize
 *
 * Description:
 * This function tokenizes the input string into an array of arguments using
 * space, newline, and tab as delimiters. It dynamically allocates memory for
 * the arguments and returns the resulting array.
 *
 * Return: An array of pointers to the tokenized arguments, or NULL on failure.
 */
char **tokenize_the_input(char *input)
{
	char **args = NULL;
	char *separator = " \n\t";
	char *token;
	int index = 0;

	token = strtok(input, separator);

	while (token != NULL)
	{
		args = (char **)realloc(args, (index + 2) * sizeof(char *));
		args[index] = (char *)malloc(strlen(token) + 1);
		strcpy(args[index], token);
		token = strtok(NULL, separator);
		index++;
	}

	args[index] = NULL;
	free(token);
	return args;
}

