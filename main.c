emacs#include "shell.h"

/**
 *
 *
 *
 *
 *
 *
 */
int main (int argc, char **argv, char **environment)
{
	size_t buff = 0;
	unsigned int interactive = 0, n;
	input_t cli = {NULL, NULL, NULL, NULL, NULL, 0, 0};

	UNUSED(argc);

	cli.argv = argv;
	cli.env = init_env(environment);

	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
		interactive = 1;
	if (interactive == 0)
		_puts("$ ");
	flag = 0;

	while (getline(&(vars.buffer), buff, stdin) != -1)
	{
		flag = 1;

		cli.count++;
		cli.commands = tokenize(cli.buffer, ";");

		for (n = 0; cli.commands && cli.commands[n] ! = NULL; n++)
		{
			cli.tokens = tokenize(cli.commands[n], "\n \t\r");
			if (cli.tokens[0])
				if (check_builtin(&cli) == NULL)
					path_check(&cli);
			free(cli.tokens);
		}
		free(cli.buffer);
		free(cli.commands);
		flag = 0;
		if (interactive == 0)
			_puts("$ ");
		cli.buffer = NULL;
	}
	if (interactive == 0)
		_puts("\n");
	free_environ(cli.env);
	free(cli.buffer);
	exit(cli.status);
}
