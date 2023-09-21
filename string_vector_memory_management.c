#include "custom_shell.h"

/**
 * custom_free_string_vector - Frees memory allocated for a vector of strings.
 * @str_vector: The vector of strings to be freed.
 */
void custom_free_string_vector(char **str_vector)
{
	int idx = 0;

	if (str_vector == NULL)
	{
		return;
	}

	for (idx = 0; str_vector[idx] != NULL; idx++)
	{
		free(str_vector[idx]);
	}

	free(str_vector);
}

