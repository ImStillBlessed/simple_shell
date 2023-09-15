#include "shell.h"

/**
 * main - Entry point for the Simple shell program
 * 
 * Return: 0 on successful exit, -1 on errors encountered.
 */

int main(void)
{
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
    char *delim = " \n"; /* the delimiter to seperate the strings input */
    size_t buff = 0;
    int ac, i = 0;
    char **av = NULL; /* argv; argument vector array */
    pid_t pid;
    int val = 0;/* for execve */

    while (1)
    {
        printf("$ "); /* default display on the trminal */

        if (getline(&cmd, &buff, stdin) == -1)
        {/* getline is already called, checking for failure */
            perror("Failed to read line");
            return (-1);
        }

        cmd_cpy = strdup(cmd);/* copy the buffer cmd into cmd_cpy*/

        token = strtok(cmd, delim);/* seperate the input string into words */

        if (strcmp(token, "exit") == 0)
        {/* check if the first input string in exit */
            free(cmd);
            return (0);/* end program */
        }
        while (token)
        {/* count the rest of the words */
            token = strtok(NULL, delim);
            ac++;
        }
        av = malloc(sizeof(char *) * ac);/* allocate memory for argv*/
        if (av == NULL)
		{
			perror("memory allocation failed\n");
			return (-1);
		}

/* form here we collect and arrange the input words to be used as commands */
        token = strtok(cmd_cpy, delim);

        while (token)
        {
            av[i] = token;
            token = strtok(NULL, delim);
            i++;
        }
        printf("tokenised successfully");
        av[i] = NULL;

        /* child process*/
        printf("before fork\n");
        pid = fork();
        if (pid == 0)
        {/* we are in child process */
        printf("child process\n");
            val = execve(av[0], av, NULL);/* NULL cause enve nor gotten yet */
            if (val == -1)
                perror("Wrong command\n");
        }
        else
        {/* we are in parent process */
            printf("parent process\n");
            wait(NULL);
        }
        
    }   
}