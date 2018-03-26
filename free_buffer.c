#include "shell.h"

/**
 * free_buffer - freeing everything for valgrind's happiness
 * @buffer: malloc'ed buffer
 * @size: size of the buffer
 * Return: void
 */
void free_buffer(char *buffer, size_t size)
{
	size_t a;

	for (a = 0; a < size; a++)
		buffer[a] = '\0';
}
