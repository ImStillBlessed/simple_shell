#include "custom_shell.h"

/**
 * getUserInput - Scans and retrieves user input command.
 *
 * @currentPath: A pointer to list_paths struct representing the current path.
 *
 * Return: The user input command after scanning.
 */
char *getUserInput(list_paths *currentPath)
{
	ssize_t bytesRead;
	size_t bufferSize = 0;
	char *userCommand = NULL;

	/* Display the prompt ($) and get input from the user */
	write(STDOUT_FILENO, "($) ", 4);
	bytesRead = getline(&userCommand, &bufferSize, stdin);

	/* Handling end of file (EOF) or Ctrl + D */
	if (bytesRead == EOF)
	{
		/* Write a new line and free memory */
		write(STDOUT_FILENO, "\n", 1);
		freePathList(currentPath);
		free(userCommand);
		exit(0);
	}

	/* If the user enters a blank line, return NULL */
	if (bytesRead == 1 && userCommand[0] == '\n')
	{
		free(userCommand);
		return (NULL);
	}

	userCommand[bytesRead - 1] = '\0';

	return (userCommand);
}

