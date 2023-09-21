#include "custom_shell.h"

/**
 * handleNonBuiltinCommand - Handle non-builtin commands
 * @cmdArgs: Array of command arguments
 * @environment: Environment variables
 * @executionStatus: Pointer to the status variable
 * @commandCount: Number of commands executed
 * @currentPath: Pointer to the list_paths structure
 * @arguments: Array of command-line arguments
 * This function handles non-builtin commands in the shell
 * by checking the access permission.
 */
void handleNonBuiltinCommand(char **cmdArgs, char *environment[], int *executionStatus,
                             int commandCount, list_paths *currentPath, char *arguments[])
{
    char *newPath;

    if (access(cmdArgs[0], X_OK) == 0)
        executeCommand(cmdArgs[0], cmdArgs, environment, executionStatus);
    else
    {
        /* If the user just entered the command without the whole path */
        newPath = checkAccess(cmdArgs[0], currentPath);
        if (newPath)
        {
            executeCommand(newPath, cmdArgs, environment, executionStatus);
            free(newPath);
        }
        else
        {
            printErrorMessage(arguments[0], commandCount, cmdArgs[0], NOT_FOUND);
            *executionStatus = NOT_FOUND;
        }
    }
}

