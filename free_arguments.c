#include "shell.h"

/**
 * free_arguments - Free memory allocated for an array of arguments
 * @args: An array of argument strings
 *
 * Description:
 * This function frees the memory allocated for an array of argument strings.
 * It also sets the array elements to NULL to avoid double freeing in the
 * calling function.
 */
void free_arguments(char **args)
{
	free(args);
}

