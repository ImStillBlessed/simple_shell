#include "custom_shell.h"

/**
 * custom_change_directory - Change the current working directory.
 * @command_tokens: Array of strings containing commands.
 * @argv: Argument vector (argv).
 *
 * Return: 0 on success, 1 on failure.
 */
int custom_change_directory(char **command_tokens, char **argv)
{
	char *new_directory = command_tokens[1];
	char current_directory[1024];

	if (getcwd(current_directory, sizeof(current_directory)) == NULL)
	{
		perror("Error in getcwd()");
		return (1);
	}

	if (new_directory == NULL || _custom_strcmp(new_directory, "~") == 0)
		new_directory = _custom_getenv("HOME");
	else if (_custom_strcmp(new_directory, "-") == 0)
		new_directory = _custom_getenv("OLDPWD");

	if (chdir(new_directory) == -1)
	{
		write(STDERR_FILENO, argv[0], _custom_strlen(argv[0]));
		write(STDERR_FILENO, ": 1", 3);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command_tokens[0], _custom_strlen(command_tokens[0]));
		write(STDERR_FILENO, ": can't cd to ", 14);
		write(STDERR_FILENO, command_tokens[1], _custom_strlen(command_tokens[1]));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	else
	{
		setenv("OLDPWD", current_directory, 1);
		if (getcwd(current_directory, sizeof(current_directory)) == NULL)
		{
			perror("Error in getcwd()");
			return (1);
		}
	}
	return (0);
}
