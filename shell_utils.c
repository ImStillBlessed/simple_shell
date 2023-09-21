#include "custom_shell.h"

/**
 * convert_line_to_array - converts a string into an array of strings
 * @input_str: the string to convert
 * @cmd_status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **convert_line_to_array(char *input_str, int cmd_status)
{
	char *copied_line, *token, **arg_vector, *var, *cmd;
	int i = 0, char_count;

	/* handle_comments(input_str); */
	if (input_str[0] == '\0')
		return (NULL);
	copied_line = _strdup(input_str);
	if (copied_line == NULL)
		return (NULL); /*can't cpy*/
	char_count = char_count(copied_line, ' ');
	arg_vector = malloc((char_count + 1) * sizeof(char *));
	token = _strtok(copied_line, TOK_D);

	cmd = handle_flags(token, input_str, arg_vector, cmd_status);
	arg_vector[i++] = cmd;
	while (token != NULL)
	{
		token = _strtok(NULL, TOK_D);
		if (token != NULL)
		{
			if (_strcmp("$$", token) == 0)
				cmd = get_process_id();
			else if (_strcmp("$?", token) == 0)
				cmd = get_status(cmd_status);
			else if ((token[0] == '$') && (token[1]))
			{
				var = custom_getenv(&token[1]);
				if (var)
					cmd = _strdup(var);
				else
					cmd = _strdup("");
			}
			else
				cmd = _strdup(token);
			arg_vector[i++] = cmd;
		}
	}
	arg_vector[i] = NULL;
	free(copied_line);
	return (arg_vector);
}

/**
 * handle_flags - Handles flags and tokens.
 * @token: The token to handle.
 * @input_str: The input string.
 * @arg_vector: The argument vector.
 * @cmd_status: The command status.
 * Return: The result of handling the token.
 */
char *handle_flags(char *token, char *input_str,
		char **arg_vector, int cmd_status)
{
	char *var, *cmd, *copied_line;

	copied_line = input_str;
	if (token == NULL)
	{
		free(arg_vector);
		free(copied_line);
		return (NULL);
	}
	if (_strcmp("$$", token) == 0)
		cmd = get_process_id();
	else if (_strcmp("$?", token) == 0)
		cmd = get_status(cmd_status);
	else if ((token[0] == '$') && (token[1]))
	{
		var = custom_getenv(&token[1]);
		if (var)
			cmd = _strdup(var);
		else
			cmd = _strdup("");
	}
	else
		cmd = _strdup(token);

	return (cmd);
}
