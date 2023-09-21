#include "custom_shell.h"

/**
 * custom_execute_command - Executes a given command.
 *
 * @command_path: The path of the command to execute.
 * @arguments: An array of strings containing the command and its arguments.
 * @environment: An array of strings representing the environment variables.
 * @exit_status: A pointer to an integer variable to set the exit status.
 *
 * Returns: NOTHING.
 */
void custom_execute_command(char *command_path, char **arguments
		, char **environment, int *exit_status)
{
	pid_t child_pid;

	child_pid = fork();
	/* Handle fork error */
	if (child_pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	/* Child process */
	if (child_pid == 0)
	{
		execve(command_path, arguments, environment);
		perror("Execve failed");
		exit(EXIT_FAILURE);
	}
	/* Parent process */
	else if (child_pid > 0)
	{
		/* Wait for the child process to complete */
		waitpid(child_pid, exit_status, WUNTRACED);
		*exit_status = WEXITSTATUS(*exit_status);
	}
}
