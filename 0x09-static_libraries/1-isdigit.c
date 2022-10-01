#include "main.h"
#include <ctype.h>

/**
 * _isdigit - function that checks a digit
 *
 * @c: return int type
 *
 * Return: return 0 on success and 1 on fail
 */

int _isdigit(int c)
{
	int i = isdigit(c);

	if (i > 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
