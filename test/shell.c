#include "shell.h"

/**
 * main - Entry point to the simple shell program.
 * Return: 0 on success -1 on failure.
 */
int main(void)
{
	size_t buffsize = 0;
	char *delim = " \n";
	char *token, *buffer = NULL, *buffcpy = NULL;

	while (1)
	{
		buffer = malloc(buffsize * sizeof(char));
		if (buffer == NULL)
		{
			fprintf(stderr, "memory allocation failed\n");
			return (-1);
		}
		printf("$ ");
		if (getline(&buffer, &buffsize, stdin) == -1)
		{
			printf("logout\n");
			free(buffer);
			exit(-1);
		}
		token = strtok(buffer, delim);
		if (token != NULL)
		{
			if (strcmp(token, "exit") == 0)
			{
				printf("process ended\n");
				free(buffer);
				return (0);
			}
			if (strcmp(token, "cat") == 0)
			{
				token = strtok(NULL, delim);
				cat(token);
			}
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, delim);
			}
		}
		free(buffer);
		printf("ran till the end\n");
	}
}
