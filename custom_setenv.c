#include "main.h"

/**
 *_cdSetenv - sets specific var
 *@data: shell's data
 *@var: variable
 *@value: its value
 *Return: 0 on success
*/

int _cdSetenv(shell_data *data, char *var, char *value)
{
	int i = 0;
	char *new_env, *env, *name;

	for (; data->_environ[i]; i++)
	{
		env = _strdup(data->_environ[i]);
		name = _strtok(env, "=");
		if (strcmp(name, var) == 0)
		{
			new_env = malloc(_strlen(var) + _strlen(value) + 2);
			_strcpy(new_env, var);
			_strcat(new_env, "=");
			_strcat(new_env, value);
			free(data->_environ[i]);
			data->_environ[i] = new_env;
			environ[i] = data->_environ[i];
			freeInputArgsData(data, 1, 0, 1);
			free(env);
			return (0);
		}
		free(env);
	}
	return (-1);
}
/**
 *_setenv - sets env var
 *@data: shell's data
 *Return: 0 on success
*/

int _setenv(shell_data *data)
{
	int i = 0;
	char *new_env, *env, *name;

	if (data->args[2] == NULL)
		data->args[2] = "";
	for (; data->_environ[i]; i++)
	{
		env = _strdup(data->_environ[i]);
		name = _strtok(env, "=");
		if (strcmp(name, data->args[1]) == 0)
		{
			new_env = malloc(_strlen(data->args[1]) + _strlen(data->args[2]) + 2);
			_strcpy(new_env, data->args[1]);
			_strcat(new_env, "=");
			_strcat(new_env, data->args[2]);
			free(data->_environ[i]);
			data->_environ[i] = new_env;
			environ[i] = data->_environ[i];
			freeInputArgsData(data, 1, 0, 1);
			free(env);
			return (0);
		}
		free(env);
	}
	new_env = malloc(_strlen(data->args[1]) + _strlen(data->args[2]) + 2);
	_strcpy(new_env, data->args[1]);
	_strcat(new_env, "=");
	_strcat(new_env, data->args[2]);
	data->_environ[i] = new_env;
	environ[i] = data->_environ[i];
	freeInputArgsData(data, 1, 0, 1);
	return (0);
}

/**
 *setenvCommand - command for setenv
 *@data: shell's data
*/

void setenvCommand(shell_data *data)
{
	if (data->args[3] != NULL)
	{
		printError(data, "./shell", ": too many arguments\n", 127);
		freeInputArgsData(data, 1, 0, 1);
		return;
	}
	if (data->args[1] == NULL && data->args[2] == NULL)
	{
		printError(data, "./shell", ": not enough arguments\n", 127);
		freeInputArgsData(data, 1, 0, 1);
		return;
	}
	_setenv(data);
}
