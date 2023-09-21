#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "custom_shell.h"

/**
 * custom_set_environment_variable - Set an environment variable
 * @variable_name: The name of the environment variable
 * @variable_value: The value to be assigned to the environment variable
 * @path_list: Pointer to the list_paths structure
 *
 * This function sets the value of an environment variable.
 */
void custom_set_environment_variable(char *variable_name, char *variable_value,
		list_paths *path_list)
{
	int total_length = 0;
	char *env_variable = NULL;

	if (variable_name == NULL || variable_value == NULL)
	{
		return;
	}
	if (path_list == NULL)
	{
		return;
	}
	total_length = _custom_strlen(variable_name) +
		_custom_strlen(variable_value) + 2;
	env_variable = malloc(total_length);
	if (env_variable == NULL)
	{
		return;
	}
	_custom_strcpy(env_variable, variable_name);
	_custom_strcat(env_variable, "=");
	_custom_strcat(env_variable, variable_value);
	env_variable[total_length - 1] = '\0';
	free(env_variable);
}
