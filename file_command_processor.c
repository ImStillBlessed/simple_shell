#include "custom_shell.h"

/**
 * processShellCommandsFromFile - Processes shell commands from a file
 * @fileName: Name of the file with shell commands
 * @shellName: Name of the shell to use
 * Return: Pointer to a char array with output
 * Opens file, reads each line, and returns pointer to char array with output.
 */
char **processShellCommandsFromFile(char *fileName, char *shellName)
{
	struct stat fileStat;
	char *fileContent, **commandLines;
	size_t bytesRead;
	int fileDescriptor;

	if (stat(fileName, &fileStat) != -1)
	{
		if (S_ISREG(fileStat.st_mode))
		{
			fileDescriptor = open(fileName, O_RDONLY);
			if (fileDescriptor == -1)
				exit(ERROR);
			if (fileStat.st_size == 0)
				exit(0);
			fileContent = malloc((fileStat.st_size + 1) * sizeof(char));
			if (!fileContent)
				return (NULL);
			bytesRead = read(fileDescriptor, fileContent, fileStat.st_size);
			if ((int)bytesRead == -1)
			{
				perror("reading error");
			}
			close(fileDescriptor);
			fileContent[bytesRead - 1] = '\0';
			if (fileContent)
				commandLines = textToArray(fileContent);
			return (commandLines);
		}
		else
			exit(0);
	}
	else
	{
		cannotOpenFileHandler(shellName, 0, fileName);
		exit(127);
	}
	return (NULL);
}

