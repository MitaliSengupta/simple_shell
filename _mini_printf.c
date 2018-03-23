#include "shell.h"

/**
** _printf - gives output
** @format: char
** Return: num of chars
**/
int _printf(const char *format, ...)
{
	unsigned int i, j, count;
	char mod;
	va_list arguments;

	pstruct print_func [] = {
		{'c', print_char}, {'s', print_string},
		{'d', print_number}, {'\0', NULL}
	};
	va_start(arguments, format);
	i = 0, j = 0, count = 0;
	while (format && format[i])
	{
		if (!(format[i] == '%' && format[i + 1]))
			{_putchar(format[i]); count++; i++; continue; } /*move to next argument*/
		mod = format[i + 1];
		while (print_func[j].type)
		{
			if (print_func[j].type == mod)
			{
				count += print_func[j].printer(arguments);
				i++;
				break;
			}
			j++;
		}
		if (print_func[j].type == '\0')
		{
			_putchar('%');
			_putchar(mod);
			count += 2;
			i++; /*move past %*/
		}
		j = 0; /*reset transverse for type if matched or hits null*/
		i++; /*move past mod*/
	}
	va_end(arguments);
	return (count);
}
/**
 * _strcmp - compares two strings
 * @s1: pointer string type char
 * @s2: pointer string type char
 * Return: 15 if s1 > s2, -15 vice versa, 0 if same
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int diff = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	diff = s1[i] - s2[i];

	return (diff);
}
/**
 * _strncpy - copies array
 * @dest: pointer array type char
 * @src: string to be copied into array
 * @n: index of src to start
 * @i: index of dest to start
 * Return: dest array type car
 */
char *_strncpy(char *dest, char *src, int i, int n)
{
	int in;

	for (in = i; src[n]; in++, n++)
		dest[in] = src[n];
	dest[in] = '\0';
	return (dest);
}
