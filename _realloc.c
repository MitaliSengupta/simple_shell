#include "shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to previously allocated memory
 * @size: ptr  to size of previously allocated memory block
 * Return: pointer to allocated memory block
 */
char **_realloc(char **ptr, size_t *size)
{
	char **newptr;
	size_t n;

	newptr = malloc(sizeof(char *) * ((*size) + 10));
	if (newptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (; n < (*size); n++)
	{
		newptr[n] = ptr[n];
	}
	*size = *size + 10;
	free(ptr);
	return (newptr);
}
