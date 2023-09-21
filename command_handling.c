#include "custom_shell.h"

/**
 * custom_check_exit - Checks if command is an "exit" command and handles it.
 * @input_command: The original command entered by the user.
 * @command_tokens:An array of strings contain the command and its arguments.
 * @current_path:A pointer to list_paths struct representing the current path.
 * @shell_program_name: The name of the shell program.
 * @command_count: The command count.
 * @exit_status: A pointer to an integer variable representing the status.
 * @environment: A pointer to an environment list.
 * @input_commands: An array of strings representing the input commands.
 *
 * Return: Nothing.
 */
void custom_exit_handler(char *input_command, char **command_tokens
		, list_paths *current_path,
		char *shell_program_name, int command_count, int *exit_status,
		list_paths *environment, char **input_commands)
{
	int exit_code;

	if (_custom_strcmp(command_tokens[0], "exit") == 0)
	{
		if (command_tokens[1] == NULL)
		{
			custom_free_all(input_commands, command_count, environment,
					current_path, input_command, command_tokens);
			exit(*exit_status);
		}
		else if (command_tokens[1] != NULL)
		{
			if (_custom_strlen(command_tokens[1]) <= 9)
			{
				exit_code = _custom_atoi(command_tokens[1]);
				if (exit_code != -1)
				{
					custom_free_all(input_commands, command_count, environment,
							current_path, input_command, command_tokens);
					exit(exit_code);
				}
				else
				{
					*exit_status = EXIT_ERROR;
					custom_print_error(shell_program_name, command_count
							, command_tokens[1], EXIT_ERROR);
				}
			}
			else
			{
				*exit_status = EXIT_ERROR;
				custom_print_error(shell_program_name, command_count
						, command_tokens[1], EXIT_ERROR);
			}
		}
	}
}

/**
 * custom_free_everything - Free memory allocated for various data structures.
 * @input_commands: An array of strings representing the input commands.
 * @command_count: The command count.
 * @environment: A pointer to an environment list.
 * @current_path:A pointer to a list_paths struct representing current path.
 * @input_command:The original command entered by user.
 * @command_tokens:An array of strings contain the command and its arguments.
 *
 * Return: Nothing.
 */
void custom_free_everything(char **input_commands,
		int command_count, list_paths *environment,
		list_paths *current_path, char *input_command, char **command_tokens)
{
	if (input_commands)
	{
		free(input_commands[command_count]);
		if (input_commands)
			free(input_commands);
	}
	custom_free_list(environment);
	custom_free_list(current_path);
	custom_free_all(input_command, command_tokens);
}

