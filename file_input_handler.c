#include "custom_shell.h"

/**
 * processCommandFiles - Process command files based on the operation mode.
 * @operationMode: The operation mode.
 * @fileName: The name of the command file.
 * @shellProgramName: The name of the shell program.
 * Return: The array of command lines read from the file.
 */
char **processCommandFiles(int operationMode
		, char *fileName, char *shellProgramName)
{
	char **commandLines;

	if (operationMode == NON_INTERACTIVE_PIPE)
	{
		commandLines = handleNonInteractivePipes();
		if (!commandLines)
			exit(0);
	}
	else if (operationMode == NON_INTERACTIVE_MODE)
	{
		commandLines = handleNonInteractiveFiles(fileName, shellProgramName);
		if (!commandLines)
			exit(0);
	}
	return (commandLines);
}

