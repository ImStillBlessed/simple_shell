#include "custom_shell.h"

/**
 * main - Function that runs the SHELL program.
 * @argumentCount: Argument Count.
 * @argumentVector: Argument vector.
 * @environmentVariables: The shell environment.
 * Return: Exit status of the program.
 */
int main(int argumentCount, char *argumentVector[]
		, char *environmentVariables[])
{
	int *exitStatus, commandCount = 0, isNonInteractive = 1
		, shellStatus = 0, operationMode;
	char *userCommand, **commandLines, **commandArray = NULL;
	list_paths *currentPath;

	exitStatus = &shellStatus;
	operationMode = custom_determine_mode(argumentCount);

	if (operationMode != INTERACTIVE_MODE)
	{
		commandLines = processCommandFiles(operationMode
				, argumentVector[1], argumentVector[0]);
	}

	currentPath = createPathList(); /* Turning path current to linked list. */

	while (isNonInteractive && ++commandCount)
	{
		if (operationMode == NON_INTERACTIVE_MODE ||
				operationMode == NON_INTERACTIVE_PIPE)
		{
			if (commandLines[commandCount - 1])
				userCommand = commandLines[commandCount - 1];
			else
			{
				custom_free_resources(commandLines);
				break;
			}
		}
		else if (operationMode == INTERACTIVE_MODE)
			userCommand = getUserInput(currentPath); /* Prompt user and get command. */

		if (!userCommand)
			continue;

		commandArray = convert_line_to_array(userCommand, *exitStatus);

		if (!commandArray)
		{
			custom_free_resources(userCommand);
			continue;
		}

		if (custom_directory_check(commandArray[0], argumentVector, commandCount
					, commandArray, exitStatus, userCommand) == 0)
			continue;

		if (custom_builtin_handler(userCommand, commandArray, currentPath
					, argumentVector[0], commandCount, exitStatus
					, NULL, commandLines, argumentVector) != 0)
			handleNonBuiltinCommand(commandArray, environmentVariables
					, exitStatus, commandCount, currentPath, argumentVector);

		custom_free_resources(userCommand, commandArray);
	}

	freePathList(currentPath);
	exit(*exitStatus);
}

