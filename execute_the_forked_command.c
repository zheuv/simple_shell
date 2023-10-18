#include "shell.h"

/**
 * execute_the_forked_command - Execute a command in a forked process
 * @args: An array of command arguments
 * @input: The user input string
 *
 * Description:
 * This function forks a new process to execute the given command. In the child
 * process, it calls execute_the_command to execute the command. If an error
 * occurs, it prints an error message and exits. In the parent process, it
 * waits for the child process to complete and returns the exit status of the
 * child process.
 *
 * Return: The exit status of the child process, or -1 on failure.
 */
int execute_the_forked_command(char **args, char *input)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execute_the_command(args, input) == -1)
		{
			perror(input);
			free(args);
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	if (wait(&status) == -1)
		perror("wait");
	if (WIFEXITED(status))
		return WEXITSTATUS(status);
	return -1;
}

