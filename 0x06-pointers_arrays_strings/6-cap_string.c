#include "main.h"
/**
*cap_string - function that capitalize first character of a word
*@str: string to capitalize
*Return:returns the capitalized string
*/
char *cap_string(char *str)
{
	int index = 0, i;
	char separators[] = {' ', '\t', '\n', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}'}; /* separators */

	while (str[++index])
	{
		char set_upper = 0;
		for (i = 0; i < 13; i++)
		{
			if (str[index - 1] == separators[i])
			{
				set_upper = 1;
				break;
			}
		}
		
		if (set_upper && str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32;
		else
			index++;
	}
	
	return (str);
}
