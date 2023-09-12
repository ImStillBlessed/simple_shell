#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include <unistd.h>

/**
 * main - Entry point to the simole shell program.
 * Return: 0 on success -1 on failure.
 */
int main()
{
	size_t buffsize = 32;
	ssize_t characters;
	char *token, *buffer;

	buffer = malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "memory allocation failed\n");
		return (-1);
	}
	printf("$ ");
	characters = getline(&buffer, &buffsize, stdin);
	if (characters == -1)
	{
		fprintf(stderr, "getline failed\n");
		free(buffer);
		exit(-1);
	}
	printf("getline worked\n");
	token = strtok(buffer, " ");
	printf("strtok worked\n");
	if (token != NULL && strcmp(token, "exit") == 0)
	{
		printf("process ended\n");
		free(buffer);
		return (0);
	}
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	free(buffer);
	printf("ran till the end\n");
	return (0);
}
