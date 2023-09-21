#include "custom_shell.h"

/**
 * processShellCommandsPipes - Processes shell commands with pipes
 * Return: Pointer to a char array with output
 */
char **processShellCommandsPipes()
{
	char buffer[2048], *inputText, **commandLines;
	size_t totalCharactersRead = 0;
	ssize_t bytesRead;
	int i, hasContent;

	hasContent = 0;
	commandLines = NULL;
	inputText = NULL;
	while ((bytesRead = read(STDIN_FILENO, buffer, 2048)) > 0)
	{
		totalCharactersRead += bytesRead;
	}
	if (bytesRead == -1)
	{
		perror("reading error");
		exit(ERROR);
	}
	if (totalCharactersRead > 2048)
	{
		buffer[2048 - 1] = '\0';
	}
	else
	{
		buffer[totalCharactersRead - 1] = '\0';
	}

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ')
		{
			hasContent = 1;
		}
	}
	if (hasContent == 0)
	{
		return (NULL);
	}
	totalCharactersRead = _strlen(buffer);
	inputText = (char *)malloc(sizeof(char) * (totalCharactersRead + 1));
	if (inputText != NULL)
	{
		_strcpy(inputText, buffer);
		inputText[totalCharactersRead] = '\0';
		commandLines = textToArray(inputText);
	}
	return (commandLines);
}

