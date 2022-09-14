#include <stdio.h>


/**
 * numLength - returns the lenth of string
 * @num : operand number
 * Return: number of digits
 */

int main(void)
{
	printf("1, 2, ");
	long x=1, y=2;
	for (int i=2;i<50;i++)
	{
		long z = x+y;
		printf("%i, ", z);
		x=y;	y=z;
	}

	printf('\n');
	return 0;
}
