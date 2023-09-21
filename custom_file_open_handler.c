#include "custom_shell.h"

/**
 * custom_file_open_handler - Handle errors occur when file cannot be opened.
 * @app_name: The name of the application attempting to open the file.
 * @count_val: A counter variable to keep track.
 * @filename: The name of the file that cannot be opened.
 *
 * Return: void.
 */
void custom_file_open_handler(char *app_name, int count_val, char *filename)
{
	char *count_str;

	count_str = number_to_string(count_val);
	write(STDERR_FILENO, app_name, _custom_strlen(app_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, count_str, _custom_strlen(count_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Cannot open ", 11);
	write(STDERR_FILENO, filename, _custom_strlen(filename));
	write(STDERR_FILENO, "\n", 1);
}
