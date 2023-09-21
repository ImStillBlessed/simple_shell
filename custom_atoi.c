#include "shell.h"

/**
 * custom_atoi - Converts a string to an integer.
 * @str: The string to be converted.
 *
 * Return: The converted integer, or -1 on conversion error.
 */
int custom_atoi(char *str)
{
	unsigned int result = 0;
	int index = 0;
	char isPositive = '\0';

	while (str[index] != '\0')
	{
		if (!((str[index] >= '0') && (str[index] <= '9')))
		{
			return (-1);
		}
		if ((str[index] >= '0') && (str[index] <= '9'))
		{
			result = (result * 10) + (str[index] - '0');
		}
		else if (str[index] == '+')
		{
			isPositive++;
		}

		index++;
	}

	return (result);

}
