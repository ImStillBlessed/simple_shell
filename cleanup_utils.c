#include "main.h"

/**
 *free_data - frees data structure
 *@data: data structure
 *Return: no return
 */

void free_data(shell_data *data)
{
	unsigned int i;

	if (environ)
	{
		for (i = 0; data->_environ[i]; i++)
		{
			free(data->_environ[i]);
		}
		free(data->_environ);
	}
	free(data->oldpwd);
}

/**
 *freeInputArgsData - frees input and args
 *@data: shell's data
 *@num1: 0 frees input
 *@num2: 0 frees args
 *@num3: 0 calls free_data;
*/

void freeInputArgsData(shell_data *data, int num1, int num2, int num3)
{
	if (num1 == 0)
		free(data->input);
	if (num2 == 0)
		free(data->args);
	if (num3 == 0)
		free_data(data);
}
