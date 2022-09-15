#include "main.h"

/**
 * print_square - Print a square with #.
 * @size: Is the size of the square.
 *
 * Return: To the value of void..
 */
void print_square(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i = 0;
		while (i < size)
		{
			for (int j = 0; j < size; j++)
			{
				_putchar('#');
			}
			i++;
			_putchar('\n');
		}
	}
}
