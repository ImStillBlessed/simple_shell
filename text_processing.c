#include "custom_shell.h"

/**
 * convert_text_to_array - converts text to an array of strings
 *
 * @text_input: the text to convert
 *
 * Return: a pointer to a char array containing the converted text
 */
char **convert_text_to_array(char *text_input)
{
	char *token, *command;
	char **command_lines;
	int i;
	unsigned int characters_count;

	characters_count = 0;
	command_lines = NULL;
	i = 0;
	characters_count = countCharacterOccurrences(text_input, '\n');
	command_lines = (char **)malloc((characters_count + 1) * sizeof(char *));
	token = custom_strtok(text_input, "\n");
	command = custom_strdup(token);
	command_lines[i++] = command;
	while (token != NULL)
	{
		token = custom_strtok(NULL, "\n");
		if (token != NULL)
		{
			command = custom_strdup(token);
			command_lines[i++] = command;
		}
	}
	free(text_input);
	command_lines[i] = NULL;
	return (command_lines);
}

