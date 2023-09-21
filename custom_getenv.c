#include "shell.h"

/**
 * custom_getenv - A function to retrieve an environment variable's value
 * @var_name: The name of the environment variable to retrieve
 * Return: The value of the specified environment variable
 */
char *custom_getenv(const char *var_name)
{
	int index;
	char *env_name;
	char *env_value;
	char *result = NULL;

	/* Loop through the environment variables stored in environ */
	for (index = 0; environ[index] != NULL; index++)
	{
		/* Get the name of the environment variable */
		env_name = strtok(environ[index], "=");
		/* Get the value corresponding to the name */
		env_value = strtok(NULL, "=");

		/* Compare user-provided variable name with list of environment variables */
		if (strcmp(env_name, var_name) == 0)
		{
			/* If found, assign the value of the environment variable to result */
			result = env_value;
			break;
		}
	}
	/* Return the value found after locating the environment variable */
	return (result);
}
