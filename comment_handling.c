#include <stddef.h>
#include "custom_shell.h"

/**
 * remove_comments - Removes comments from the input string.
 *
 * @input_str: The input string.
 */
void remove_comments(char *input_str)
{
	int index = 0;
	char current_character;
	int in_quotes = 0;

	for (index = 0; input_str[index] != '\0'; index++)
	{
		current_character = input_str[index];

		if (current_character == '"')
		{
			in_quotes = !in_quotes;
		}
		if (current_character == '#' && !in_quotes)  /* Ex: echo "hello #world" */
		{
			input_str[index] = '\0';
			break;
		}
	}
}

