#include "main.h"

/**
 * print_diagonal - Print a diagonal if the number is positive.
 * @n: The character to be count.
 *
 * Return: To the value of c.
 */
void print_diagonal(int n)
{
	int i = 0, ii;

	while (i < n && n > 0)
	{
		ii = 0;
		while (ii < i)
		{
			_putchar(' ');
			ii++;
		}

		_putchar('\\');
		_putchar('\n');
		i++;
	}
	if (i == 0)
		_putchar('\n');
}
