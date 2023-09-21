#include "custom_shell.h"

/**
 * processToken - Processes a token and returns the corresponding string.
 * @inputToken: The input token to process.
 * @commandStatus: An integer representing the status of the command.
 * Return: A dynamically allocated string representing the processed token.
 */
char *processToken(char *inputToken, int commandStatus)
{
	char *result, *environmentVariable;

	result = NULL;
	environmentVariable = NULL;

	if (_strcmp("$$", inputToken) == 0)
		result = getProcessID();
	else if (_strcmp("$?", inputToken) == 0)
		result = getStatus(commandStatus);
	else if (inputToken[0] == '$' && inputToken[1] != '\0')
	{
		environmentVariable = getEnvironmentVariable(&inputToken[1]);
		result = (environmentVariable != NULL) ?
			_strdup(environmentVariable) : _strdup("");
	}
	else
		result = _strdup(inputToken);

	return (result);
}

