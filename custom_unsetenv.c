#include "main.h"

/**
 *_unsetenv - unsets env var
 *@data: shell's data
 *Return: 0 on success
*/

int _unsetenv(shell_data *data)
{
	int i = 0, j;
	char *env, *name;

	while (data->_environ[i])
	{
		env = _strdup(data->_environ[i]);
		name = _strtok(env, "=");
		if (_strcmp(name, data->args[1]) == 0)
		{
			free(data->_environ[i]);
			for (j = i; data->_environ[j]; j++)
				data->_environ[j] = data->_environ[j + 1];
			freeInputArgsData(data, 1, 0, 1);
			free(env);
			return (0);
		}
		free(env);
		i++;
	}
	return (-1);
}

/**
 *unsetenvCommand - unsetenv command
 *@data: shell's data
*/

void unsetenvCommand(shell_data *data)
{
	if (data->args[2] != NULL)
	{
		printError(data, "./shell", ": too many arguments\n", 127);
		freeInputArgsData(data, 1, 0, 1);
		return;
	}
	if (data->args[1] == NULL)
	{
		printError(data, "./shell", ": not enough arguments\n", 127);
		freeInputArgsData(data, 1, 0, 1);
		return;
	}
	if (_unsetenv(data) == -1)
	{
		printError(data, "./shell", ": var do not exist\n", 127);
		freeInputArgsData(data, 1, 0, 1);
	}
}
