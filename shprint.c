#include "shell.h"
/**
 * shell_print - Print a string to the standard output
 * @str: The string to print
 */
void shell_print(char *str)
{
	write(1, str, strlen(str));
}
