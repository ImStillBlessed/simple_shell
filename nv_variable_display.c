#include "custom_shell.h"

/**
 * displayEnvironmentVariables - Displays the environment variables.
 * @executionStatus: A pointer to an integer variable to set the status.
 *
 * Each variable is printed on a separate line.
 * The 'executionStatus' parameter is used to set the status of the function.
 * Return: Nothing.
 */
void displayEnvironmentVariables(int *executionStatus)
{
	int index;

	/* Iterate over the environment variables until a NULL is encountered */
	for (index = 0; environ[index] != NULL; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, "\n", 1);
	}
	/* Set the execution status to indicate successful completion */
	*executionStatus = 0;
}

