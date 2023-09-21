#include "custom_shell.h"

/**
 * custom_free_string_array - Frees memory allocated for an array of strings.
 * @str_array: The array of strings to be freed.
 *
 * This function deallocates memory for an array of strings.
 */
void custom_free_string_array(char **str_array)
{
	char **current_str;

	/* Check if the input pointer is NULL */
	if (str_array == NULL)
	{
		return;
	}

	/* Set the current_str pointer to the start of the array */
	current_str = str_array;

	/* Iterate over each string in the array */
	while (*current_str != NULL)
	{
		/* Free the memory for the current string */
		free(*current_str);
		/* Move to the next string in the array */
		current_str++;
	}

	/* Free the memory allocated for the array itself */
	free(str_array);
}

