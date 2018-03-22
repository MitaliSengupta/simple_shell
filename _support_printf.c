#include "shell.h"

/**
** _putchar - writes the character c to stdout
** @c: The character to print
**
** Return: On success 1.
** On error, -1 is returned
**/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
** print_char - prints character
** @arg: char to print
** Return: 0 success
**/
int print_char(va_list arg)
{
	char i;

	i = va_arg(arg, int);
	_putchar(i);
	return (1);
}
/**
** print_string - prints string
** @arg: string to print
** Prints string
** Return: string length
**/
int print_string(va_list arg)
{
	unsigned int i;
	char *str;

	str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * print_number - print numbers
 * @arg: va_list of arguments
 * Return: number count
 */
int print_number(va_list arg)
{
	int maxint = 1000000000;
	int minint = INT_MIN;
	int number = va_arg(arg, int);
	int i, count = 0, trigger = 0;
	/* if negative and not max min int */
	if (number < 0 && number > minint)
	{
		_putchar('-');
		count++;
		number *= -1;
	}
	if (number == 0)
	{
		_putchar('0');
		count++;
	}
	if (number == minint) /* cut off lass number then convert to positive */
	{
		number = (number % (maxint / 10)) * -1;
		_putchar('-');
		count++;
		trigger = 1;
	}
	for (i = 0; i < 10; i++) /* print digit by digit */
	{
		if (number / maxint != 0) /* loop till find left more digit */
		{
			_putchar(((number / maxint) % 10) + '0'); /* print digit*/
			count++;
		}
		maxint /= 10; /* lower the divisior or go through the digits left to right*/
	}
	if (trigger == 1) /* if max min digt put back the last digit */
	{
		_putchar('8');
		count++;
	}
	return (count);
}
