#include "shell.h"

/**
 * _strcat - appends a string to another
 * @dest: string to append to
 * @src: string to be appended
 * Return: merged string
 */
char *_strcat(char *dest, char *src)
{
	char *new;
	unsigned int s1 = 0, s2 = 0, len, i, n;

	if (dest == NULL)
		s1 = 0;
	else
	{
		for (; dest[s1]; s1++)
			;
	}
	if (src == NULL)
		s2 = 0;
	else
	{
		for (; dest[s2]; s2++)
			;
	}
	len = s1 + s2 + 2;
	new = malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	for (i = 0; i < s1; i++)
		new[i] = dest[i];
	newp[i] = '/';

	for (n = 0; n < s2; n++)
		new[i + 1 + n] = src[n];
	new[s1 + s2 + 1] = '\0';
	return (new);
}

/**
 * _strlen - gets length of string
 * @s: string to count
 * Return: Length of string.
 */
unsigned int _strlen(char *s)
{
	unsigned int i = 0;

	for (; s[i]; i++)
		;
	return (i);
}
/**
 * _strncmp - compare string up to n length
 * @s1: string thats getting checked
 * @s2: comparing to
 * @n: amount of byes to search
 * Return: amount of bytes thats matched
 */
int _strncmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 *
 *
 *
 *
 *
 */
char *_strdup(char *duplicate)
{
	char *dup;
	int n = 0, i =0;

	if (duplicate == 0)
		return (NULL);
	for (; duplicate[n]; n++)
		;
	dup = malloc((n + 1) * sizeof(char));

	for (; i <= n; i++)
		dup[i] = duplicate[i];
	return (dup);
}

/**
 *
 *
 *
 *
 *
 */
ssize_t _puts(char *s)
{
	ssize_t num, len;

	num = _strlen(s);

	len = write(STDOUT_FILENO, s, num);
	if (len != num)
	{
		perror("The enterprise is lost");
		return (-1);
	}
	return (len);
}
