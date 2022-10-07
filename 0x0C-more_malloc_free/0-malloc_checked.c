#include "main.h"


/**
 *malloc_checked - allocates memory to the heap using malloc,  terminates with 98 if failure
 *@b: size of the memory that should ne allocated 
 *
 * Return: pointer to the adress allocated by malloc
 */

void *malloc_checked(unsigned int b)
{
	void *x = malloc(b);
	if (x == null)
	{
		exit(98);
	}

	return x;
}
