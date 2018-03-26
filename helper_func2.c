#include "shell.h"

/**
 *
 *
 *
 *
 *
 *
 *
 */
void _printer(char *s)
{
	ssize_t count, len;

	count = _strlen(s);
	len = write(STDERR_FILENO, s, count);

	if (len != count)
	{
		perror("Abandon Ship");
		exit(1);
	}
}

/**
 *
 *
 *
 *
 *
 *
 */
char *_int_str(unsigned int count)
{
	char *str;
	unsigned int temp = 0, len = 0;

	temp = count;

	for (; temp != 0; len++)
		temp /= 10;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		perror("Fatal Error - Abandon Ship");
		exit(127);
	}
	str[len] = '\0';
	for (--len; count; --len)
	{
		str[len] = (count % 10) + '0';
		count /= 10;
	}
	return (str);
}
