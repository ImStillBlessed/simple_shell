#include "custom_shell.h"

/**
 * custom_determine_mode - A function that determines the mode of the terminal.
 *
 * @argument_count: The count of arguments.
 *
 * Return:
 *   1 for interactive mode.
 *   0 for non-interactive mode with a pipe.
 *  -1 for non-interactive mode without a pipe.
 *  -1 for an error.
 */
int custom_determine_mode(int argument_count)
{
	struct stat stdin_status;

	fstat(STDIN_FILENO, &stdin_status);

	if (argument_count == 1 && isatty(STDIN_FILENO))
		return (INTERACTIVE_MODE);

	if (!isatty(STDIN_FILENO) && argument_count == 1)
		return (NON_INTERACTIVE_PIPE);

	if (argument_count >= 1)
		return (NON_INTERACTIVE_MODE);

	return (ERROR);
}
