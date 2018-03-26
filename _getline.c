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
ssize_t parsing(char **buffer, int file, int *end_of_file)
{
	int num, count = 0;
	char buff[BUF_LENGTH];

	if (!buffer)
		return (-1);
	*buffer = malloc(sizeof(char));
	if (*buffer == NULL)
		return (-1);
	(*buffer)[0] = '\0';

	free_buffer(buff, BUF_LENGTH); /* everytime will flush buffer when valgrinding */
	num = read(file, buff, BUF_LENGTH - 1);

	while (num > 0)
	{
		buff[num + 1] = '\0';
		*buffer = _strnconcat(*buffer, buff, num);
		count += num;

		if (tty_checker(file) && buff[num] == '\0')
			break;
	}
	if (num == 0)
		*end_of_file = 1;
	if (num == -1)
		return (-1);
	return (count);
}

/**
 *
 *
 *
 *
 *
 *
 *
 */
ssize_t _getline(char **buffer, char **line, char **remainder, int file, int *end_of_file)
{
	char *check;
	ssize_t checker;

	if (!line || !remainder)
		return (-1);
	if (*remainder == NULL)
	{
		if (file == STDIN_FILENO)
			write(STDOUT_FILENO, "$ ", 2);
		checker = parsing(buffer, file, end_of_file);
		if (checker <= 0)
		{
			if (*buffer != NULL)
				free(*buffer);
			return (checker);
		}
		check = _strtok(line, *buffer, ";\n\0", remainder);
	}
	else
	{
		check = _strtok(line, NULL, ";\n\0", remainder);
	}
	if (*remainder == NULL)
		free(*buffer);
	if (check == NULL)
	{
		free(*buffer);
		return (-1);
	}
	return (_strlen(check) + 1);
}
