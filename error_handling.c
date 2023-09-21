#include "custom_shell.h"

/**
 * printErrorMessage - Prints an error message to the standard error stream.
 * @shellProgramName: The name of the shell program.
 * @commandCount: The command count.
 * @errorCommand: The command or argument causing the error.
 * @errorType: The type of error.
 * Return: Nothing.
 */
void printErrorMessage(char *shellProgramName, int commandCount,
		char *errorCommand, int errorType)
{
	char *countString;

	/* Convert the command count to a string */
	countString = intToString(commandCount);

	/* Print the shell program name, command count, and colon separator */
	write(STDERR_FILENO, shellProgramName, _strlen(shellProgramName));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, countString, _strlen(countString));
	write(STDERR_FILENO, ": ", 2);

	/* Check the type of error and print the corresponding error message */
	if (errorType == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, errorCommand, _strlen(errorCommand));
		write(STDERR_FILENO, "\n", 1);
	}
	else if (errorType == NOT_FOUND)
	{
		write(STDERR_FILENO, "not found\n", 10);
	}
	else if (errorType == PERMISSION_DENIED)
	{
		write(STDERR_FILENO, "Permission denied\n", 18);
	}

	/* Free the memory allocated for the converted command count */
	free(countString);
}

