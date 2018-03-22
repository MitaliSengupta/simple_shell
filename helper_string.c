#include "shell.h"

/**
 * *_strcpy - copies array
 * @dest: pointer array type char
 * @src: string to be copied into array
 * Return: dest array type car
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - appends a string to another
 * @dest: string to append to
 * @src: string to be appended
 * Return: merged string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i]; i++)
		;
	for (j = 0; src[j]; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';

	return (dest);
}

/**
 * _strstr - function that locates the substring
 * @haystack: string thats being searched
 * @needle: string to look for
 * Return: address of the beginning of the string
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	for (i = 0; haystack[i]; i++)
	{
		for (j = 0; needle[j]; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (needle[j] == '\0')
			return (haystack + i);
	}
	return (NULL);
}
/**
 * _strlen - gets length of string
 * @s: string to count
 * Return: Length of string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (-1);
	while (s[i])
		i++;
	return (i);
}
/**
 * _strncmp - compare string up to n length
 * @s1: string thats getting checked
 * @s2: comparing to
 * @n: amount of byes to search
 * Return: amount of bytes thats matched
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i;

	if (!((s1 || s2) || n))
		return (-1);
	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
