#include "custom_shell.h"

/**
 * countCharacterOccurrences - Counts the occurrences of character in a string
 *
 * @str: The string to search for the character
 * @character: The character to search for
 * Return: The number of occurrences of @character in @str
 */
unsigned int countCharacterOccurrences(char *str, char character)
{
	unsigned int occurrenceCount = 0;

	while (*str != '\0')
	{
		if (*str == character)
			occurrenceCount++;
		str++;
	}

	return (occurrenceCount + 1);
}

