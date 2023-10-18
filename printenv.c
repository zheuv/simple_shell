#include "shell.h"
/**
 * printenv - Print environment variables
 */
void printenv(void)
{
	char *env_copy;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		env_copy = *env;
		shell_print(env_copy);
	}
}
