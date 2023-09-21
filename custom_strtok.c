#include "shell.h"

/**
 * custom_strtok - Custom implementation of strtok.
 * @input_str: The input string to tokenize.
 * @delimiters: A string containing the delimiter characters.
 * Return: A pointer to the next token or NULL if no more tokens are found.
 */
char *custom_strtok(char *input_str, const char *delimiters)
{
	return (strtok(input_str, delimiters));
}
