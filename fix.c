#include "shell.h"

/**
 * main - Entry point for the Simple shell program
 * 
 * Return: 0 on successful exit, -1 on errors encountered.
 */

int main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL;
	size_t buff = 0;
	int ac;
	char **av = NULL;
	pid_t pid;

	while (1)/*while loop continues indefinately*/
	{
		printf("$ "); /* default display on the terminal */
		if (getline(&cmd, &buff, stdin) == -1)
		{/* getline is already called, checking for failure */
			perror("Failed to read line");
			free(cmd), free(cmd_cpy), free(av);
			continue;
		}
		cmd_cpy = strdup(cmd);
		ac = count(cmd_cpy);
		if (ac == -1)
			continue;
		av = malloc(sizeof(char *) * (ac + 1));
		if (av == NULL)
                {
			perror("argv memory allocation failed\n");
			free(cmd), free(cmd_cpy);
			continue;
		}
		av = split(cmd, ac);
		if (av[0] && strcmp(av[0], "exit") == 0)
		{/* check if the first input string in exit */
			free(cmd), free(cmd_cpy), free(av);
			return (0);/* end program */
		}
		if (strcmp(av[0], "cd") == 0)
		{
			if (ac != 2)
			{
				perror("wrong arguments");
				continue;
			}
			else if (chdir(av[1]) != 0)
				perror("error");
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed\n");
			free(cmd), free(cmd_cpy), free(av);
		}
		else if (pid == 0)
		{/* we are in child process */
			if (execvp(av[0], av) == -1)/*file not executable*/
				break;
		}
		else
		{/* we are in parent process */
			wait(NULL);
			free(av);
		}
	}
	perror("problem");
	free(cmd), free(cmd_cpy), free(av);
	return (0);
}

/**
 * count - counts the words/commands in string
 * @str: string to count
 * Return: The number of words in the string else NULL.
 */
int count(char *str)
{
	char *token, *args, *delim = " \n";
	int i = 0;

	if (str == NULL)
		return (-1);
	token = strtok(str, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		i++;
	}
	return (i);
}

/**
 * slpit - splits a string into words
 * @str: strimg to split.
 * @count: possible number of words.
 * Return: array of the strings.
 */
char **split(char *str, int count)
{
	char *token, *delim = " \n";
	char **args;
	int i = 0;

	args = malloc(sizeof(char *) * (count + 1));
	token = strtok(str, delim);
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	return (args);
}
