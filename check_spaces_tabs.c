#include "shell.h"

/**
 * check_spaces_tabs - Check if a string contains only spaces and tabs
 * @str: The string to check
 *
 * Description:
 * This function checks if the input string contains only spaces and tabs. If
 * the string contains any character other than space or tab, it returns 0. If
 * the string consists only of spaces and tabs, it returns 1.
 *
 * Return: 1 if the string contains only spaces and tabs, 0 otherwise.
 */
int check_spaces_tabs(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

