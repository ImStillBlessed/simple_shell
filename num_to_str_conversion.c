#include "custom_shell.h"

/**
 * intToString - Converts an integer to a string.
 * @num: The integer to be converted.
 *
 * Return: The string representation of the integer,
 * or NULL on failure.
 */
char *intToString(int num)
{
	int digits = 0, temp = num;
	char *result;

	/* Count the digits in the input number */
	if (num == 0)
		digits = 1;
	else
	{
		while (temp != 0)
		{
			temp = temp / 10;
			digits++;
		}
	}

	/* Allocate memory for the character array */
	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
	{
		perror("malloc error");
		return (NULL);
	}

	/* Set the null terminator at the end of the array */
	result[digits] = '\0';

	/* Convert each digit of the integer to a character and store in the array */
	while (digits != 0)
	{
		digits--;
		result[digits] = '0' + num % 10;
		num = (num / 10);
	}

	/* Return the converted string */
	return (result);
}

