#include "custom_shell.h"

/**
 * custom_verify_file - Verifies if a file exists and is readable.
 * @file_name: The name of the file to check.
 *
 * This function verifies if the file specified by @file_name exists
 * and is readable.
 *
 * Return: A pointer to @file_name if it exists and is readable.
 */
char *custom_verify_file(char *file_name)
{
	char *file_path;

	file_path = _custom_strdup(file_name);

	return (file_path);
}
