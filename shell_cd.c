#include "main.h"

/**
 *getWorkingDirectory - gets working directory
 *Return: pointer to the current working dir
*/

char *getWorkingDirectory()
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return (NULL);
	}
	return (cwd);
}

/**
 *cdHome - change directory to home
 *@data: shell's data
 *Return: 0 for success
*/

int cdHome(shell_data *data)
{
	char *home, *val;

	home = _getenv("HOME");
	if (home == NULL && data->args[1] == NULL)
	{
		printError(data, "shell: ", ": HOME not set\n", 0);
		freeInputArgsData(data, 1, 0, 1);
		return (0);
	}
	if (data->args[1] == NULL || _strcmp(data->args[1], "~") == 0)
	{
		data->oldpwd = getWorkingDirectory();
		chdir(home);
		val = getcwd(NULL, 0);
		if (val)
		{
			_cdSetenv(data, "PWD", val);
			free(val);
		}
		freeInputArgsData(data, 1, 1, 1);
		return (0);
	}
	return (1);
}

/**
 *cdDirAbsolute - cd with absolute path
 *@data: shell's data
 *Return: 0 for success
*/

int cdDirAbsolute(shell_data *data)
{
	char cwd[256], *val;

	if (_strncmp(data->args[1], "/", 1) == 0)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd");
			return (1);
		}
		_strcat(cwd, data->args[1]);
		if (access(cwd, F_OK) == 0)
		{
			data->oldpwd = getWorkingDirectory();
			if (chdir(cwd) == -1)
				printError(data, data->args[1], ": permission denied\n", 0);
			val = getcwd(NULL, 0);
			if (val)
			{
				_cdSetenv(data, "PWD", val);
				free(val);
			}
			freeInputArgsData(data, 1, 1, 1);
			return (0);
		}
		else
		{
			printError(data, data->args[1], ": no such file or directory\n", 0);
			freeInputArgsData(data, 1, 0, 1);
			return (0);
		}
	}
	return (1);
}

/**
 *cdDirRelative - cd with relative path
 *@data: shell's data
 *Return: 0 for success
*/

int cdDirRelative(shell_data *data)
{
	char *val;

	if (_strcmp(data->args[1], "-") == 0)
		return (1);
	if (access(data->args[1], F_OK) == 0)
	{
		data->oldpwd = getWorkingDirectory();
		if (chdir(data->args[1]) == -1)
			printError(data, data->args[1], ": permission denied\n", 0);
		val = getcwd(NULL, 0);
		if (val)
		{
			_cdSetenv(data, "PWD", val);
			free(val);
		}
		freeInputArgsData(data, 1, 1, 1);
		return (0);
	}
	else
	{
		printError(data, data->args[1], ": no such file or directory\n", 0);
		freeInputArgsData(data, 1, 0, 1);
		return (0);
	}
	return (1);
}

/**
 *cdOldPwd - cd to old dir
 *@data: Shell's data
 *Return: 0 for success
*/

int cdOldPwd(shell_data *data)
{
	char *val;

	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == NULL)
		{
			printError(data, "./shell", ": OLDPWD not set\n", 0);
			freeInputArgsData(data, 1, 0, 1);
			return (0);
		}
		if (chdir(data->oldpwd) == -1)
		{
			printError(data, "./shell", ": Failed to change to OLDPWD\n", 0);
			freeInputArgsData(data, 1, 0, 1);
			return (0);
		}
		val = getcwd(NULL, 0);
		if (val)
		{
			_cdSetenv(data, "PWD", val);
			free(val);
		}
		printString(data->oldpwd);
		printString("\n");
		freeInputArgsData(data, 1, 1, 1);
	}
	return (1);
}
