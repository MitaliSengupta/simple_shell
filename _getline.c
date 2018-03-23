#include "shell.h"

/**
 * _getline - custom getline function
 * @lineptr: buffer to fill
 * @n: number of bytes to get
 * Return: number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n)
{
	ssize_t readcount;
	size_t bytes = 100, maxbytes = 1024, i;
	char *buffer;

	if (*n > 1)
		bytes = *n;
	if (*lineptr == NULL)
		buffer = malloc(sizeof(char) * maxbytes);
	else
		buffer = *lineptr;

	do {
		readcount = read(STDIN_FILENO, buffer, bytes);
		if (readcount == -1)
			return (-1);
		for (i = 0; buffer[i]; i++)
		{
			if (buffer[i] == '\n' || buffer[i] == '\t')
				buffer[i] = '\0';
		}
		if (buffer[i] == '\0')
		{
			buffer = _realloc(buffer, 0, i);
			break;
		}
		i++;
	} while (1);

	*lineptr = buffer;
	n = &i;
	return ((ssize_t) bytes);

}
