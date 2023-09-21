#include "custom_shell.h"

/**
 *custom_get_status_string - Retrieves string representation of a status value.
 *
 * @status_value: The status value to convert to a string.
 *
 * Return: A pointer to a string representing the status value.
 */
char *custom_get_status_string(int status_value)
{
char *status_str;

    /* Convert the status value to a string */
status_str = custom_status_to_string(status_value);

    /* Return the string representation of the status value */
return (status_str);
}

