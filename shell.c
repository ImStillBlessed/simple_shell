#include "shell.h"

/**
 * main - Entry point for the Simple shell program
 * 
 * Return: 0 on successful exit, -1 on errors encountered.
 */

int main(void)
{
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *delim = " \n";/* the delimiter to seperate the strings input */
	size_t buff = 0;
	int ac, i = 0;
	char **av = NULL;/* argv; argument vector array */
	pid_t pid;
	int val = 0;/* for execve */

/**
* setting the PATH variable so the commands can be called directly.
*/
	char *new_path = "/bin/";
	if (setenv("PATH", new_path, 1) == -1)
	{
		perror("Unable to set PATH");
		free(cmd), free(cmd_cpy), free(av);
		return (-1);
	}
    

	while (1)/*while loop continues indefinately*/
	{
		printf("$ "); /* default display on the terminal */

/*
 * getline is used to collect input fron the standard input. (stdin)
 * and paste it in the buffer @cmd
 * */
		if (getline(&cmd, &buff, stdin) == -1)
		{/* getline is already called, checking for failure */
			perror("Failed to read line");
			free(cmd), free(cmd_cpy), free(av);
			return (-1);
		}

		cmd_cpy = strdup(cmd);
/* copy the buffer cmd into cmd_cpy*/
		token = strtok(cmd, delim);
/* seperate the input string into words */

		if (token && strcmp(token, "exit") == 0)
		{/* check if the first input string in exit */
			free(cmd), free(cmd_cpy), free(av);
			return (0);/* end program */
		}
		ac = 0;

		while (token)
		{/* count the rest of the words */
			token = strtok(NULL, delim);
			ac++;
		}
		av = malloc(sizeof(char *) * (ac + 1));
/* allocate memory for argv*/
		if (av == NULL)
		{
			perror("argv memory allocation failed\n");
			free(cmd);
			free(cmd_cpy);
			continue;
		}

/* form here we collect and arrange the input words to be used as commands */
		token = strtok(cmd_cpy, delim);
		i = 0;

		while (token)
		{
			av[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		av[i] = NULL;

/*check if the command is 'cd' to change directory*/
		if (strcmp(av[0], "cd") == 0)
		{
			if (ac != 2)
				perror("wrong argument");
			else
			{
				if (chdir(av[1]) != 0)
					perror("error");
			}
		}
/* child process*/
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed\n");
			free(cmd), free(cmd_cpy), free(av);
		}
		else if (pid == 0)
		{/* we are in child process */
			execvp(av[0], av);
			if (val == -1)/*file not executable*/
				perror("Wrong command\n");
			free(cmd);
			free(cmd_cpy);
			free(av);
			exit(EXIT_FAILURE);
		}
		else
		{/* we are in parent process */
			wait(NULL);
			free(av);
		}
	}
	free(cmd);
	free(cmd_cpy);
	return (0);
}
