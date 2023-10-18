#include "shell.h"

/**
 * read_the_input - Read user input from stdin
 * @input: A pointer to the input string
 * @buf_size: A pointer to the buffer size
 *
 * Description:
 * This function reads user input from the standard input (stdin) using the
 * getline function and stores it in the input buffer. It dynamically resizes
 * the buffer as needed. If an error occurs during input reading, it will
 * display an error message and exit the program.
 *
 * Return: The number of characters read, or -1 on error.
 */
ssize_t read_the_input(char **input, size_t *buf_size)
{
	ssize_t rd;

	rd = getline(input, buf_size, stdin);
	if (rd == -1)
	{
		free(*input);
		perror("getline()");
		exit(EXIT_FAILURE);
	}

	if ((*input)[rd - 1] == '\n')
		(*input)[rd - 1] = '\0';

	return (rd);
}

