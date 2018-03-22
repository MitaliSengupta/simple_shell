#include "shell.h"

/**
 * _echo - prints sys varables, stdin, pid
 * @tokens: command and arguments
 * @env: enviroment variables used for getenv()
 * Return: SUCCESS or FAILURE
 */
int _echo(char **tokens, char **env)
{
	pid_t pid;
	char *value;
	int check;

	if (tokens[1])
	{
		if (tokens[1][0] == '$')/*get enviroment var*/
		{
			if (tokens[1][1] == '$')
			{
				pid = getpid();
				_printf("%d\n", (int) pid);
				return (EXIT_SUCCESS);
			}
			if (tokens[1][1] != '\0')
			{
				value = &tokens[1][1];/*set KEY after $*/
				tokens[1] = _getenv(value, env); /*replace KEY with VALUE*/
			}
		}
		if (tokens[1][0] == '*' && tokens[1][1] == '\0')/* ls current directory*/
		{
			tokens[0] = "ls";
			tokens[1] = ".";
			if (cmdchk(tokens, env) != 0)
				return (EXIT_FAILURE);
		}
	}
	check = cmdExec(tokens, env);/*execute cmd which updated tokens*/
	/*if (trig == 1)*/
		/*free(tokens[1]);*/
	if (check == EXIT_FAILURE)
	{
		perror("Echo Execution Failed");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * _cd - changes directory
 * @tokens: command and arguments
 * @env: enviroment variables used for getenv()
 * Return: SUCCESS or FAILURE
 */
int _cd(char **tokens, char **env, char *home)
{
	int check, i = 0, j = 0;
	char *buff;
	size_t size = 256;

	buff = malloc(sizeof(char) * 256);
	if (tokens[1] == NULL)
		check = chdir(home);
	else if (tokens[1][0] == '-')
		check = chdir(_getenv("OLDPWD", env));
	else
		check = chdir(tokens[1]);
	if (check == -1)
	{
		perror("CD Failed");
		return (EXIT_FAILURE);
	}
	else
	{
		buff = getcwd(buff , size);
		while (!_strncmp(env[i], "PWD", 3))
			i++;
		while (!_strncmp(env[j], "OLDPWD", 6))
			j++;
		env[j] = _strncpy(env[j], env[i], 6, 3);
		env[i] = _strncpy(env[i], buff, 4, 0);
	}
	free(buff);
	return (EXIT_SUCCESS);
}

/**
 * _env - prints enviroment
 * @env: enviroment variables used for getenv()
 * Return: SUCCESS or FAILURE
 */
int _env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		_printf("%s\n", env[i]);
	return (EXIT_SUCCESS);
}

/**
 * _cp - function that copies the content of a file to another file
 * @tokens: tokens[1] is copy and tokens[2] is paste.
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int _cp(char **tokens)
{
	int fdC, fdP, count;
	char *copy = tokens[1], *paste = tokens[2];
	char buffer[1024];

	if (copy == NULL || paste == NULL)
	{
		perror("cp: missing file operand");
		return (EXIT_FAILURE);
	}
	fdC = open(copy, O_RDONLY);
	fdP = open(paste, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fdC == -1 || fdP == -1)
		return (EXIT_FAILURE);

	do {/*read multiple times if more content then given size*/
	count = read(fdC, buffer, 1024);
	if (count != 0)
		count = write(fdP, buffer, count);
	if (count == -1)
		break;
	} while (count); /*untill count becomes 0*/

	count = close(fdC), count = close(fdP);
	if (count == -1)
	{
		perror("CP Failed");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
