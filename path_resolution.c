#include "main.h"

/**
 *inputFix - fixes input from \n and spaces
 *@data: all relevent data
 *Return: 0 for success
 */

int inputFix(shell_data *data)
{
	int cp = 0;
	/*char *errormsg;*/

	escapeChars(data);
	removeExtraSpace(data);
	cp = isOnlyNull(data);
	if (cp == 1)
		return (1);
	fixDataInput(data);
	if (_strcmp(data->input, "env") == 0)
		return (2);
	if (!_getenv("PATH") && _strchr(data->input, '/') == NULL)
	{
		if (_getenv("PATH1"))
			printError(data, "./shell: 1: ", ": not found\n", 127);
		else
			printError(data, "./hsh: 1: ", ": not found\n", 127);
		return (1);
	}
	return (0);
}

/**
 *commandChecker - functions check commands
 *@data: command line
 */

void commandChecker(shell_data *data)
{
	int check;

	check = isExecutable(data);
	if (check == 0)
		commandExe(data);
	else if (check == 1)
		isBuildin(data);
	else
		free(data->args);
}

/**
 *checkSlash - functions check slash command
 *@data: command line
 *@lepath: path from previous function
 *Return: 0 for first case, 2 for second case
 */

int checkSlash(shell_data *data, char *lepath)
{
	struct stat file_stat;

	if (stat(data->input, &file_stat) == 0)
	{
		getCmdArgs(data, data->input);
		free(lepath);
		return (0);
	}
	else
	{
		errorHandler(data);
		free(lepath);
		return (2);
	}
}

/**
 *isExecutable - is file executable
 *@data: shell's data
 *Return: 0 for success
*/

int isExecutable(shell_data *data)
{
	char *path = isPath();
	char *dir = _strtok(path, ":");
	char filepath[256] = {0};
	int compt = 0;

	if (data->input)
	{
		if (_strchr(data->input, '/') != NULL)
		{
			return (checkSlash(data, path));
		}
		while (dir != NULL && compt == 0)
		{
			_strcpy(filepath, dir);
			_strcat(filepath, "/");
			_strcat(filepath, data->input);
			if (access(filepath, X_OK) == 0)
			{
				compt++;
			}
			if (compt == 0)
				dir = _strtok(NULL, ":");
		}
		if (compt > 0)
		{
			getCmdArgs(data, filepath);
			free(path);
			return (0);
		}
		else
		{
			free(path);
			return (1);
		}
	}
	free(path);
	return (1);
}
