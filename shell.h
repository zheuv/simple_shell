#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

extern char **environ;


int my_shell(void);
ssize_t read_the_input(char **input, size_t *buf_size);
int validate_the_command(char **args, char *input, int exit_num);
int handle_the_builtins(char **args, char *input, int exit_num);
void free_arguments(char **args);
int execute_the_forked_command(char **args, char *input);
int execute_the_command(char **args, char *input);
int does_command_exist(char **args);
int check_spaces_tabs(char *str);
char **tokenize_the_input(char *input);
void handle_sig(int sig);
void shell_print(char *str);
void printenv(void);

#endif
