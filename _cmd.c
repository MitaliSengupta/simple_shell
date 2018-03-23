#include "shell.h"

/**
 * cmdExec - execute executables found in PATH
 * @tokens: command and arguments
 * @env: current enviroment
 * Return: Status or Failure
 */
int cmdExec(char **tokens, char **env)
{
	pid_t pid;
	int status, check;

	pid = fork();
	if (pid == -1)
		perror("Failed to Fork");
	if (pid == 0)
	{
		check = execve(tokens[0], tokens, env);
		if (check == -1)
			_exit(EXIT_FAILURE);
	}
	else
		wait(&status);

	return (status);
}

/**
 * specialExec - executes special cmds func like echo, cd, set, unset
 * @tokens: command and its arguments
 * @env: current enviroment
 * @controller: point to the right special function to execute the cmd
 * @home: path to home
 * Return: SUCCESS or FAILURE
 */
int specialExec(char **tokens, char **env, int controller, char *home)
{
	int check;

	/*if cmd is null or controller is <= 0*/
	if (tokens[0] == NULL || controller <= 0)
		return (EXIT_FAILURE);

	if (controller == 1)/* ECHO */
		check = _echo(tokens, env);
	else if (controller == 2)/* CD */
		check = _cd(tokens, env, home);
	else if (controller == 3)/* ENV */
		check = _env(env);
	else if (controller == 4)/* HISTORY */
		check = history(home);
	else if (controller == 5)/* CP */
		check = _cp(tokens);
	else/* ADD MORE SPECIAL CASES */
	{
		perror("Special Execution Failed");
		return (EXIT_FAILURE);
	}

	if (check == EXIT_FAILURE)
	{
		perror("Special Execution Failed");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
