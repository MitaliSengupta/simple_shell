#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#define UNUSED(x) (void)(x)

/**
* struct printf_functions - struct to match type with printer funcitons
* @type: input to determine type of printf function
* @printer: specific printf function
* Description: the the correct copy function to use
**/
typedef struct printf_functions
{
	char type;
	int (*printer)();
} pstruct;

/*strtok function*/
char *_strtok(char *str, const char *delim);

/*command function*/
int cmdExec(char **tokens, char **env);
int specialExec(char **tokens, char **env, int controller, char *home);
int _echo(char **tokens, char **env);
int _cd(char **tokens, char **env, char *home);
int _env(char **env);
int _cp(char **tokens);

/*Printf*/
int _printf(const char *format, ...);
int _putchar(char c);
int print_percent(void);
int print_char(va_list arg);
int print_string(va_list arg);
int print_number(va_list arg);

/*STRING*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, char *needle);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int i, int n);

/*tokenizer*/
char **tokenize(char *string, const char *delimiter);
int cmdchk(char **token, char **environ);
char *delimiters(char *s);

/*MEMORYFUNC*/
char *_strdup(char *str);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/*free memory*/
char **ptofree(char *p, int n);

/*SIGNAL*/
void signal_handler(int s);

#endif
