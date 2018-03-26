#include "shell.h"

/**
 *
 *
 *
 *
 *
 */
void _env(input_t *inputs)
{
	unsigned int a = 0;

	for (; inputs->env[a]; a++)
	{
		_puts(inputs->env[a]);
		_puts("\n");
	}
	inputs->status = 0;
}

/**
 *
 *
 *
 *
 *
 *
 */
void _setenv(input_t *inputs)
{
	char **path;
	char *inp;

	if (inputs->tokens[1] == NULL || inputs->tokens[2] == NULL)
	{
		_error(inputs, ": Wrong number of inputs - Access Denied\n");
		inputs->status = 2;
		return;
	}
	path = find_env(inputs->env, inputs->tokens[1]);
	if (path == NULL)
		add_env(inputs);
	else
	{
		inp = add_value(inputs->tokens[1], inputs->tokens[2]);
		if (inp == NULL)
		{
			_error(inputs, NULL);
			free(inputs->buffer);
			free(inputs->commands);
			free(inputs->tokens);
			free_env(inputs->env);
			exit(127);
		}
		free(*path);
		*path = inp;
	}
	inputs->status = 0;
}


/**
 *
 *
 *
 *
 *
 *
 */
void _unsetenv(input_t *inputs)
{
	char **path, **new;
	unsigned int n = 0, i = 0;

	if (inputs->tokens[1] == NULL)
	{
		_error(inputs, ": Wrong number of inputs - Access Denied\n");
		inputs->status = 2;
		return;
	}
	path = find_env(inputs->env, inputs->tokens[1]);
	if (path == NULL)
	{
		_error(inputs, ": Cannot unset imaginary input\n");
		return;
	}
	for (; inputs->env[i] != *path; i++)
		new[i] = inputs->env[i];
	for (n = i + 1; inputs->env[n] != NULL; n++, i++)
		new[i] = inputs->env[n];
	new[i] = NULL;
	free(*path);
	free(inputs->env);
	inputs->env = new;
	inputs->status = 0;
}
