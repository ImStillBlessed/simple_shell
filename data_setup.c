#include "main.h"

/**
 *sigintHandler - handles ^C
 *@signal: Ctr+C
 */

void sigintHandler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n($) ", 5);
	fflush(stdout);
}

/**
 *errorHandler - functions handle errors
 *@data: command line
 */

void errorHandler(shell_data *data)
{
	perror(data->input);
	/*return;*/
}

/**
 *setData - sets data for shell
 *@data: shell's data
 *@av: argv
*/

void setData(shell_data *data, char **av)
{
	int i = 0;

	data->av = av;
	data->input = NULL;
	data->cmd = NULL;
	data->args = NULL;
	data->status = 0;
	data->space = 0;
	data->oldpwd = NULL;

	if (environ)
	{
		for (i = 0; environ[i]; i++)
			;

		data->_environ = malloc(sizeof(char *) * (i + MAX_ENV + 1));

		for (i = 0; environ[i]; i++)
		{
			data->_environ[i] = _strdup(environ[i]);
		}
		while (i < MAX_ENV)
		{
			data->_environ[i] = NULL;
			i++;
		}
	}
}

/**
 *commandExe - function executes comands
 *@data: shell's data
*/

void commandExe(shell_data *data)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("faild to fork");
		data->status = -1;
		exitCommand(data);
	}
	else if (pid == 0)
	{
		if (execve(data->cmd, data->args, data->_environ) == -1)
		{
			errorHandler(data);
			data->status = -1;
			exitCommand(data);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free(data->cmd);
		free(data->args[0]);
		free(data->args);
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
			data->status = 2; /*added for exit 2 */
	}
}
