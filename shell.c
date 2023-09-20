#include "shell.h"

/**
 * main - Entry point for the Simple shell program
<<<<<<< HEAD
 *
=======
>>>>>>> 246ffd8522a9ed97fde6a29af931b415833eacab
 * Return: 0 on successful exit, -1 on errors encountered.
 */

int main(void)
{
<<<<<<< HEAD
	char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *delim = " \n"; /* the delimiter to seperate the strings input */
	size_t buff = 0;
	int ac, i = 0;
	char **av = NULL; /* argv; argument vector array */
	pid_t pid;
	int val = 0;/* for execve */

	/**
	 * setting the PATH variable so the commands can be called directly.
	 */
	char *new_path = "/usr/local/bin:/usr/bin:/bin";
	if (setenv("PATH", new_path, 1) == -1)
	{
		perror("Unable to set PATH");
		free(cmd), free(cmd_cpy), free(av);
		return (-1);
	}


	while (1)
	{
		printf("$ "); /* default display on the trminal */

		if (getline(&cmd, &buff, stdin) == -1)
		{/* getline is already called, checking for failure */
			perror("Failed to read line");
			free(cmd), free(cmd_cpy), free(av);
			return (-1);
		}

		cmd_cpy = strdup(cmd);/* copy the buffer cmd into cmd_cpy*/

		token = strtok(cmd, delim);/* seperate the input string into words */

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
		av = malloc(sizeof(char *) * (ac + 1));/* allocate memory for argv*/
		if (av == NULL)
		{
			perror("argv memory allocation failed\n");
			free(cmd),  free(cmd_cpy);
			continue;
=======
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
			continue;
		}
		cmd_cpy = strdup(cmd);
		ac = count(cmd_cpy);
		if (ac == -1)
			continue;
		av = split(cmd, ac);
		check(av, ac);
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed\n");
			free(cmd), free(cmd_cpy), free(av);
		}
		else if (pid == 0)
		{/* we are in child process */
			if (execvp(av[0], av) == -1)/*file not executable*/
				return (0);
		}
		else
		{/* we are in parent process */
			wait(NULL);
			free(av);
		}
		free(cmd);
		free(cmd_cpy);
		free(av);
	}
}

/**
 * check - checks if the string entered is an inbuilt command
 * @args: the array of words entered
 * @argc: number of words entered
 * Return: 0 on sucess.
 */
int check(char **args, int argc)
{
	if (args[0] && strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(args[0], "cd") == 0)
	{
		if (argc != 2)
		{
			perror("bash: cd: argument error\n");
			return (1);
>>>>>>> 246ffd8522a9ed97fde6a29af931b415833eacab
		}
		else if (chdir(args[1]) != 0)
			perror("error");
	}
	return (0);
}

/**
 * count - counts the words/commands in string
 * @str: string to count
 * Return: The number of words in the string else NULL.
 */
int count(char *str)
{
	char *token, *delim = " \n";
	int i = 0;

<<<<<<< HEAD
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

		/* child process*/
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed\n");
			free(cmd), free(cmd_cpy), free(av);
		}

		else if (pid == 0)
		{/* we are in child process */
			val = execve(av[0], av, NULL);/* NULL cause enve nor gotten yet */
			if (val == -1)
				perror("Wrong command\n");
			free(cmd), free(cmd_cpy), free(av);
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
=======
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
 * split - splits a string into words
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
>>>>>>> 246ffd8522a9ed97fde6a29af931b415833eacab
}
