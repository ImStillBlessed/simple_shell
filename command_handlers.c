#include "main.h"

/**
 *isBuildin - checks if cmd is a building
 *@data: shell's data
*/


void isBuildin(shell_data *data)
{
	if (_strcmp(data->input, "exit") == 0)
		exitCommand(data);
	else if (_strcmp(data->input, "cd") == 0)
		cdCommand(data);
	else if (_strcmp(data->input, "setenv") == 0)
		setenvCommand(data);
	else if (_strcmp(data->input, "unsetenv") == 0)
		unsetenvCommand(data);
	else
	{
		printError(data, "./shell", ": not found\n", 0);
		free(data->args);
		return;
	}
}


/**
 *cdCommand - handles cd
 *@data: shell's data
*/

void cdCommand(shell_data *data)
{
	errno = E2BIG;
	/*argument list too long*/
	if (data->args[2] != NULL)
	{
		errorHandler(data);
		freeInputArgsData(data, 1, 0, 1);
		return;
	}
	if (cdHome(data) == 0)
		return;
	if (cdDirAbsolute(data) == 0)
		return;
	if (cdDirRelative(data) == 0)
		return;
	if (cdOldPwd(data) == 0)
		return;
}

/**
 *exitCommand - handles exit command
 *@data:shell's data
*/

void exitCommand(shell_data *data)
{
	errno = E2BIG;

	if (data->args[1] == NULL)
	{
		freeInputArgsData(data, 0, 0, 0);
		free(data->oldpwd);
		exit(data->status);
	}
	if (isNumber(data->args[1]) == 0)
	{
		printError(data, "shell", ": unrecognized argument\n", 127);
		data->exitstring = 1;
		freeInputArgsData(data, 1, 0, 1);
		data->status = 2;
		return;
	}
	data->status = atoi(data->args[1]);
	if (data->args[2] != NULL)
	{
		errorHandler(data);
		freeInputArgsData(data, 1, 0, 1);
		return;
	}
	if (data->status < 0)
		printError(data, "./shell", ": Illegal number\n", 255);
	freeInputArgsData(data, 0, 0, 0);
	free(data->oldpwd);
	exit(data->status);
}

/**
 *PrintEnv - prints the environment
 *@data:shell data
*/

void printEnv(shell_data *data)
{
	int i = 0;

	if (data->args[1] != NULL)
	{
		printError(data, "./shell", " No such file or directory\n", 127);
	}
	else if (strcmp(data->input, "env") == 0)
	{
		for (; data->_environ[i]; i++)
		{
			printString(data->_environ[i]);
			printString("\n");
		}
	}
	else
		printError(data, "./shell", "  command not found\n", 127);
	free(data->args);
}
