#include "shell.h"

/**
 *
 *
 *
 *
 *
 */
unsigned int matching(char n, const char *s)
{
	unsigned int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (n == s[i])
			return (i);
	}
	return (0);
}

/**
 * _strtok - splits string based of delimiter
 * Uses Static var to remember string.
 * @str: input string thats duplicated and modified
 * @delim: delimiter used to break the duplicated string
 * Return: individual tokens or NULL if fails
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_1;
	static char *next;
	unsigned int n;

	if (str != NULL)
		next = str;
	token_1 = next;
	if (token_1 == NULL)
		return (NULL);
	for (n = 0; next[n] != '\0'; n++)
	{
		if (matching(next[n], delim) == 0)
			break;
	}
	if (next[n] == '\0'; || next[n] == '#')
	{
		next = NULL;
		return (NULL);
	}
	token_1 = next + n;
	next = token_1;

	for (n = 0; next[n] ! = '\0'; n++)
	{
		if (matching(next[n], delim) == 1)
			break;
	}
	if (next[n] == '\0')
		next == NULL;
	else
	{
		next[n] = '\0';
		next = next + n + 1;
		if (*next == '\0')
			next == NULL;
	}
	return (token_1);
}
