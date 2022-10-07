#include "main.h"

/**
 *string_nconcat - concatenates a whole string and a number of charectors from the second string
 *@s1: pointer to the first string's adress 
 *@s2 pointer to the second string's adress
 *@n the number of charectors of the second string thst should be concatenated
 *
 * Return: pointer to the new concatenated string's adress
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int _one = sizeof(s1), _two - sizeof(s2);
	unsigned int ni = n > _two ? _two : n + 1; 
	
	char *p = malloc(_one + _two);


	if (p == null)
	{
		retun Null;
	}


	for (unsigned int i = 0;i < _one;i++)
	{
		p[i] = s1[i]	
	}
	for (unsigned int i = _one;i< _one+_two;i++)
	{
		p[i] = s2[i - _one];
	}

	if (p[_one + _two] != '\0')
		p[_one + _two] = '\0';
		
	return p;
}
