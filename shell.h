#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>

#define UNUSED(x) (void)(x)

extern unsigned int flag;

typedef struct input
{
	char **tokens;
	char *buffer;
	char **env;
	char **commands;
	char **argv;
	int status;
	size_t count;
} input_t;

typedef struct command
{
	char *comm;
	void(*f)(int_t *);
} command_t;

/* Environ: _env.c, set_unsetenv.c */

char **init_env(char **environ);
void free_environ(char **environ);
void _setenv(input_t *inputs);
void _unsetenv(input_t *inputs);

/* Helper functions: helper_func.c , helper_func2.c */

char *_strcat(char *dest, char *src);
unsigned int _strlen(char *s);
int _strncmp(char *s1, char *s2);
char *_strdup(char *duplicate);
ssize_t _puts(char *s);
void _printe(char *s);
char *_int_str(unsigned int count);

/* Memory management: _realloc.c */

char **_realloc(char **ptr, size_t *size);

/* Signal management: _signal.c */

static void sig_handler(int sig_handler);

/* custom string token: _strtok.c , tokenizer.c */

unsigned int matching(char n, const char *s);
char *_strtok(char *str, const char *delim);
char **tokenize(char *arguments, char *delimiter);



#endif
