#include "shell.h"

/**
 * tokenize -  splits string into smaller strings
 * and palces them in an array
 * @arguments: string being examined
 * @delimiter: where the sting is being split
 * Return: array of char pointers representing tokens
 */
char **tokenize(char *arguments, char *delimiter)
{
	char **tokens = NULL;
	size_t i, numtokens = 10;

	if (arguments == NULL)
		return (NULL);
	/*allocate space in char *array  to hold tokens from string*/
	tokens = malloc(sizeof(char *) * (numtokens));
	if (tokens == NULL)
	{
		perror("You have reached the final frontier");
		return (NULL);
	}
	while ((tokens[i] = _strtok(arguments, delimiter)) != NULL)
	{
		i++;
		if (i == numtokens)
		{
			tokens = _realloc(tokens, &numcount);
			if (tokens == NULL)
			{
				perror("You are now on a different dimension");
				return (NULL);
			}
		}
		arguments = NULL;
	}
	return (tokens);
}
