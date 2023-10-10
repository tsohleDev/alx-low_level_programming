#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints an int, float, char or string based on a format string
 *
 * @format: format string/template
 *
 * Return: void
*/

void print_all(const char * const format, ...)
{
	va_list args;

	va_start(args, format);

	int i = 0;

	while (format[i])
	{

		switch (format[i])
			{
				case 'i':
					printf("%i", va_arg(args, int));
					break;
				case 'f':
					printf("%f", va_arg(args, double));
					break;
				case 'c':
					printf("%c", va_arg(args, int));
					break;
				case 's':
					char *str_arg = va_arg(args, char *);

					if (str_arg == NULL)
						printf("(nil)");
					else
						printf("%s", str_arg);
					break;
				default:
					break;
			}
		i++;
		if (format[i])
		printf(", ");
	}


	printf("\n");
	va_end(args);
}
