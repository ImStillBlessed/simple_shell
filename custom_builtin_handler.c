#include "shell.h"

/**
 * custom_builtin_handler - Handles custom built-in commands in the shell.
 * @user_command: The original command entered by the user.
 * @command_tokens: An array of strings containing the parsed command.
 * @current_path:A pointer to a list_paths struct represent the current path.
 * @shell_name: The name of the shell.
 * @command_count: The count of the commands entered in the shell.
 * @exit_status: A pointer to an integer variable to set the exit status.
 * @environment_list: A list of environment variables.
 * @arg_values: An array of argument values.
 * @command_lines: An array of command lines.
 *
 * Return:The function returns 0 on successful execution of a built-in command,
 * -1 if the command is not a built-in command,
 * or an error occurs.
 */
int custom_builtin_handler(char *user_command, char **command_tokens
		, list_paths *current_path, char *shell_name, int command_count
		, int *exit_status, list_paths *environment_list
		, char **arg_values, char **command_lines)
{
	int i, built_in_index;
	char *built_in_commands[] = {"env", "exit", "cd", "setenv"};

	built_in_index = -1;

	/* Check if the entered command is a built-in command */
	for (i = 0; i < 4; i++)
	{
		if (_custom_strcmp(built_in_commands[i], command_tokens[0]) == 0)
		{
			built_in_index = i;
			break;
		}
	}

	/* If the command is not a built-in command, return -1 */
	if (built_in_index == -1)
		return (built_in_index);

	/* Execute the corresponding built-in command */
	switch (built_in_index)
	{
		case 0:
			custom_print_env(exit_status);
			break;
		case 1:
			custom_exit_handler(user_command, command_tokens,
					current_path, shell_name, command_count, exit_status, environment_list
					, command_lines);
			break;
		case 2:
			custom_cd(command_tokens, arg_values);
			break;
		case 3:
			custom_setenv(command_tokens[1], command_tokens[2], current_path);
			break;
		default:
			return (-1);
	}
	return (0);
}
