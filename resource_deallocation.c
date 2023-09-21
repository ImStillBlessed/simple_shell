#include "custom_shell.h"
/* Betty Ok */

/**
 * custom_free_resources - Frees allocated memory resources.
 * @input_command: Pointer to the input command string.
 * @command_tokens: Pointer to the array of command and its arguments.
 *
 *This function frees the memory allocated for input command and its arguments.
 */
void custom_free_resources(char *input_command, char **command_tokens)
{
	free(input_command);
	custom_free_argument_array(command_tokens);
}

