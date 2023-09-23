#include "main.h"

/**
 *escapeChars - change \n with \0
 *@data: shell data
 */


void escapeChars(shell_data *data)
{
	int len, i = 0;
	char *str = data->input;

	len = strlen(str);

	for (; i < len; i++)
	{
		if (data->input[i] == '\n')
			data->input[i] = '\0';
	}
}

/**
 *removeExtraSpace - removes extra space
 *@data: shell data
 */

void removeExtraSpace(shell_data *data)
{
	int i, j;
	int spaceFound = 0;
	int leadingSpaces = 0;

	for (i = 0; data->input[i] != '\0'; i++)
	{
		if (data->input[i] != ' ')
			break;
		leadingSpaces++;
	}
	for (i = leadingSpaces, j = 0; data->input[i] != '\0'; i++)
	{
		if (data->input[i] == ' ')
		{
			if (!spaceFound)
			{
				data->input[j++] = ' ';
				spaceFound = 1;
			}
		}
		else
		{
			data->input[j++] = data->input[i];
			spaceFound = 0;
		}
	}
	while (j > leadingSpaces && data->input[j - 1] == ' ')
		j--;
	data->input[j] = '\0';
}

/**
 *fixDataInput - handles input
 *@data: shell data
 */

void fixDataInput(shell_data *data)
{
	int i = 1, j = 1;
	const int MAX_ARGS = 25;
	char *token;

	data->input = _strtok(data->input, " ");
	data->args = (char **)malloc(sizeof(char *) * MAX_ARGS);
	for (; j < MAX_ARGS; j++)
	{
		data->args[j] = NULL;
	}
	token = _strtok(NULL, " ");
	while (token != NULL)
	{
		data->args[i] = token;
		i++;
		token = _strtok(NULL, " ");
	}
}

/**
 *isOnlyNull - checks if input empty string
 *@data: relevent data
 *Return:must return 0 if not NULL
 */

int isOnlyNull(shell_data *data)
{
	if (_strcmp(data->input, "") == 0)
		return (1);
	return (0);
}

/**
 *countTokens - counts tokens in string
 *@str: string to be examened
 *@delimiter: how to count
 *Return: count;
*/

int countTokens(char *str, char *delimiter)
{
	int count = 0;
	char *strCopy = _strdup(str);
	char *token = _strtok(strCopy, delimiter);

	while (token != NULL)
	{
		count++;
		token = _strtok(NULL, delimiter);
	}

	free(strCopy);
	return (count);
}
