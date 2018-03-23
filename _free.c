#include "shell.h"

/**
 * ptofree - saves malloced pointers
 * @p: pointer to save
 * @n: stage
 * Return: double pointer holding malloced pointers
 */
char **ptofree(char *p, int n)
{
	static char *pp[20];
	int i = 0;

	if (!n & !p)
	{
		while (i < 10)
		{
			pp[i] = NULL;
			i++;
		}
	}
	else if (!p && n == -1)
	{
		i = 0;
		while (pp[i])
			free(pp[i]), i++;
		return (NULL);
	}
	else
	{
		i = 0;
		while (pp[i])
			i++;
		pp[i] = p;
	}
	return (pp);
}
