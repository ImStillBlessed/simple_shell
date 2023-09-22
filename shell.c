#include "main.h"

/**
 *displayPrompt - displays prompt
 *Return: 0 for success
*/

/*int displayPrompt(void)
{
	char buffer[1024];

	if (getcwd(buffer, sizeof(buffer)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	printString("\n");
	printString("(\x1B[36m$\x1B[0m)--[");
	printString("\x1B[35m");
	printString(buffer);
	printString("\x1B[0m");
	printString("]--(\x1B[36m$\x1B[0m)\n");
	printString("\x1B[91m>>\x1B[0m ");
	return (0);
}*/

/**
 *loopPrompt - shell's loop
 *@data: shell's data
*/

void loopPrompt(shell_data *data)
{
	int n, count, eof, loop = 1;
	size_t buff;
	char *input_copy;

	while (loop == 1)
	{
		/*displayPrompt();*/
		write(STDIN_FILENO, "($) ", 4);
		eof = _getline(&data->input, &buff, stdin);
		if (eof != -1)
		{
			data->exitstring = 0;
			input_copy = _strdup(data->input);
			count = countTokens(input_copy, " ");
			if ((_strncmp(data->input, "exit", 4) == 0) && (count == 1 || count == 2))
				free(input_copy);
			n = inputFix(data);
			if (n == 0)
				commandChecker(data);
			else if (n == 2)
				printEnv(data);
			if (data->exitstring != 1)
				free(input_copy);
		}
		else
		{
			loop = 0;
			if (data->space != 1)
				free(data->input);
			else
			{
				data->input = _strdup(input_copy);
				free(data->input);
			}
		}
	}
}
