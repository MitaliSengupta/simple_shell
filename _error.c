#include "shell.h"

/**
 *
 *
 *
 *
 *
 */
void _error(input_t *inputs, char *message)
{
	char *count;

	_printer(inputs->argv[0]);
	_printer(": ");
	count = _int_str(inputs->count);
	_printer(count);
	free(count);
	_printer(": ");
	_printer(inputs->tokens[0]);
	if (message)
	{
		_printer(message);
	}
	else
		perror("");
}
