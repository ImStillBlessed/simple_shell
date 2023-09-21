#include "custom_shell.h"

/**
 * custom_get_pid_string - Retrieves the string representation of the current
 * process ID.
 *
 * Return: A pointer to a string representing the process ID.
 */
char *custom_get_pid_string()
{
	char *pid_str;
pid_t pid = getpid();

    /* Convert the process ID to a string */
pid_str = custom_pid_to_string(pid);

    /* Return the string representation of the process ID */
return (pid_str);
}

