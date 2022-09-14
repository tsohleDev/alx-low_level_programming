#include <stdio.h>


/**
 * numLength - returns the lenth of string
 * @num : operand number
 * Return: number of digits
 */

void main (void)
{
	printf("1, 2, ");
	for (unsigned int i=2,x=1,y=2;i<50;i++)
	{
		unsigned int z = x+y;
		printf("%i", z);
		x=y;	y=z;
	}
}
