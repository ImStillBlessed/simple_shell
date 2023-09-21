#include "shell.h"

/**
 * convert_integer_to_string - Converts an integer to a string.
 * @n: The integer to convert.
 * @str_buffer: The buffer to store the resulting string.
 */
void convert_integer_to_string(int n, char *str_buffer)
{
	int temp;
	int str_index = 0;

	if (n == 0)
	{
		str_buffer[str_index++] = '0';
	}

	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		str_index++; /* Calculate the length of the string needed */
	}

	temp = n;
	while (str_index > 0)
	{
		/* Store rightmost digit and move backward */
		str_buffer[--str_index] = temp % 10 + '0';
		temp /= 10; /* Remove the rightmost digit */
	}

	str_buffer[str_index] = '\0'; /* Null-terminate the string */
}

