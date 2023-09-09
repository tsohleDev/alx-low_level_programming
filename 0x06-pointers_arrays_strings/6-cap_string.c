#include "main.h"
/**
*cap_string - function that capitalize first character of a word
*@str: string to capitalize
*Return:returns the capitalized string
*/
char *cap_string(char *str)
{
	int index = 0;
	char separators[] = {' ', '\t', '\n', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}'}; /* separators */

	while (str[++index])
	{
		bool set_upper = false;
		for (int i = 0; i < 13; i++)
		{
			if (str[index - 1] == separators[i])
			{
				set_upper = true;
				break;
			}
		}
		
		if (set_upper && str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32';
		else
			index++;
	}
	
	return (str);
}
