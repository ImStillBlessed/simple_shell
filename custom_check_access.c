#include "custom_shell.h"

/**
 * custom_check_access - A function that checks access
 * for a given command in the command line.
 *
 * @current_path_list: A linked list representing the current path.
 * @user_command: A line from the user entered by getline and path list.
 *
 * Return: The full path of the command if it is found and accessible.
 * If it fails, it returns NULL.
 */
char *custom_check_access(char *user_command, list_paths *current_path_list)
{
	char *full_path;
	int is_path_found, total_length, command_length, current_path_length;

	if (current_path_list == NULL)
		return (NULL);

	while (current_path_list)
	{
		current_path_length = _custom_strlen(current_path_list->path);
		command_length = _custom_strlen(user_command);
		total_length = (current_path_length + command_length + 2);

		/* Allocate memory for the full path based on its length */
		full_path = (char *)malloc(total_length * sizeof(char));
		/* Copy the current path to the full path */
		_custom_strcpy(full_path, current_path_list->path);

		/* Make it a directory */
		_custom_strcat(full_path, "/");
		/* Get the supposed exact location in memory */
		_custom_strcat(full_path, user_command);
		/* Check access for the command in its full path */
		is_path_found = 0;

		if (access(full_path, X_OK) == 0)
		{
			is_path_found = 1;
			break;
		}
		else
			free(full_path);

		/* Traverse the full path */
		current_path_list = current_path_list->next;
	}

	if (is_path_found)
		return (full_path);
	else
		return (NULL);
}
