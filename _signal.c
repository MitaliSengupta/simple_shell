#include "shell.h"

/**
 * sig_handler - handles ctrl + c signal interruption
 * @sig_handler: signal recieved - unused
 * Return: void
 */
static void sig_handler(int sig_handler)
{
	(void) sig_handler;

	if (flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}
