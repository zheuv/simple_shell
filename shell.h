#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
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
int str_length(char *s);
char *str_copy(char *dest, char *src);
int str_compare(char *s1, char *s2);
char *str_concatenate(char *dest, char *src);
char *str_sprintf(char *str, char *delimiter, char *src);
char **tokenize_the_input(char *input);

#endif
