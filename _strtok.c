#include "shell.h"

/**
 * _strtok - splits string based of delimiter
 * Uses Static var to remember string.
 * @str: input string thats duplicated and modified
 * @delim: delimiter used to break the duplicated string
 * Return: individual tokens or NULL if fails
 */
char *_strtok(char *str, const char *delim)
{
	static char *token_1;
	static size_t i;
	char *token;
	size_t j;

	if (str == NULL && i == 0)/*if str is null and never been run before*/
		return (NULL);
	if (str != NULL)/*during the first run*/
	{
		token = _strdup(str);/*duplicate string*/
		for (i = 0; token[i]; i++)/*loop through token*/
		{
			for (j = 0; delim[j]; j++)/*loop through delim*/
			{
				if (token[i] == delim[j])/*if match*/
				{
					i++;/*duplicate remainder of token for latter access*/
					token_1 = _strdup(&token[i]),	i--;/*replace delim with null*/
					token[i] = '\0';
					token = _realloc(token, 0, i);/*realloc to required amount*/
					if (token_1 == NULL || token == NULL)
						return (NULL);
					return (token);
				}
				if (token[i] == '\n')/*no match but when string ends in \n*/
				{
					free(token_1);/*free static token1 used to save remainder*/
					return (token);
				}
			}
		}
		if (token == NULL)/*no match return duplicate copy*/
		{
			free(token_1);
			return (token);
		}
	}
	if (str == NULL)/*strtok(NULL,delim); access rest of tokens*/
		return (_strtok(token_1, delim));/*use previously saved remainder*/
	return (NULL);
}
