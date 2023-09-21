#include "custom_shell.h"

/**
 * custom_directory_check - Checks if a directory exists and is accessible.
 * @directory_path: The name of the directory to check.
 * @argv: Argument vector.
 * @command_count: The count of commands.
 * @command_tokens: Command tokens.
 * @exit_status: Pointer to the exit status.
 * @original_command_line: The original command line.
 *
 * Return: 1 if the directory exists and is accessible, else 0.
 */
int custom_directory_check(char *directory_path, char **argv
		, int command_count,
		char **command_tokens, int *exit_status, char *original_command_line)
{
	struct stat directory_stat;

	if (stat(directory_path, &directory_stat) == 0)
	{
		if (S_ISDIR(directory_stat.st_mode))
		{
			custom_print_error(argv[0], command_count
					, command_tokens[0], PERMISSION_DENIED);
			*exit_status = PERMISSION_DENIED;
			custom_free_all(original_command_line, command_tokens);
			return (0);
		}
	}
	return (-1);
}

