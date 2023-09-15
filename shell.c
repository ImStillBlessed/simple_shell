#include "shell.h"

/**
 * main - Entry point for the Simple shell program
 * 
 * Return: 0 on successful exit, -1 on errors encountered.
 */

int main(void)
{
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
    char *delim = " \n";
    size_t buff = 0;
    int ac, i = 0;
    char **av = NULL;

    while (1)
    {
        printf("$ ");
        if (getline(&cmd, &buff, stdin) == -1)
        {
            perror("Failed to read line");
            return (-1);
        }
        cmd_cpy = strdup(cmd);
        token = strtok(cmd, delim);
        if (strcmp(token, "exit") == 0)
        {
            free(cmd);
            return (0);
        }
        while (token)
        {
            token = strtok(NULL, delim);
            ac++;
        }
        av = malloc(sizeof(char *) * ac);

        token = strtok(cmd_cpy, delim);

        while (token)
        {
            av[i] = token;
            token = strtok(NULL, delim);
            i++;
        }

        av[i] = NULL;
    }   
}