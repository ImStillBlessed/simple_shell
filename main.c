#include "main.h"

/**
 *main - main
 *@ac: argument count
 *@av: argument vector
 *Return: should return 0 on success
 */

int main(int ac, char **av)
{
	shell_data data;
	(void)ac;

	signal(SIGINT, sigintHandler);
	setData(&data, av);
	loopPrompt(&data);
	free_data(&data);
	return (data.status);
}
