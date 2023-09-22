#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>

#define ENOREC 100
#define MAX_ENV 100

extern char **environ;

/**
 *struct data - struct contains all shell data
 *@av: args vector
 *@input: command line written by user
 *@args: tokens of command line
 *@status: last status of shell
 *@cmd: command
 *@_environ: environment variable
 *@space: checks space
 *@exitstring: checks exit string
 *@oldpwd: old working dirctory
 */
typedef struct data
{
	char **av;
	char *input;
	char *cmd;
	char **args;
	int status;
	char **_environ;
	int space;
	int exitstring;
	char *oldpwd;
} shell_data;

/*data_setup.c*/
void sigintHandler(int signal);
void errorHandler(shell_data *data);
void setData(shell_data *data, char **av);
void commandExe(shell_data *data);

/*path_resolution.c*/
void commandChecker(shell_data *data);
int isExecutable(shell_data *data);
void buildinFunction(shell_data *data);
int inputFix(shell_data *data);
int checkSlash(shell_data *data, char *lepath);

/*error_handling.c*/
void getCmdArgs(shell_data *data, char *path);
char *isPath(void);
char *errorMaker(shell_data *data, char *str, char *str2);
void printError(shell_data *data, char *str1, char *str2, int status);

/*shell.c*/
void loopPrompt(shell_data *data);
/*int displayPrompt(void);*/
/*input_processing.c*/
void escapeChars(shell_data *data);
void removeExtraSpace(shell_data *data);
int isOnlyNull(shell_data *data);
void fixDataInput(shell_data *data);
int countTokens(char *str, char *delimiter);

/*command_handlers.c*/
void isBuildin(shell_data *data);
void cdCommand(shell_data *data);
void exitCommand(shell_data *data);
void printEnv(shell_data *data);

/*shell_cd.c*/
char *getWorkingDirectory(void);
int cdHome(shell_data *data);
int cdDirRelative(shell_data *data);
int cdDirAbsolute(shell_data *data);
int cdOldPwd(shell_data *data);

/*cleanup_utils.c*/
void free_data(shell_data *data);
void freeInputArgsData(shell_data *data, int num1, int num2, int num3);

/*custom_getline.c*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);
int _getc(FILE *stream);
size_t malloc_usable_size(const void *ptr);
char *_getenv(char *var);

/*custom_setenv.c*/
void setenvCommand(shell_data *data);
int _setenv(shell_data *data);
int _cdSetenv(shell_data *data, char *var, char *value);

/*custom_unsetenv.c*/
void unsetenvCommand(shell_data *data);
int _unsetenv(shell_data *data);

/*string_utils.c*/
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
void printString(char *str);
int _putchar(char c);

/*character_utils.c*/
int _isdigit(int c);
int isNumber(char *str);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strtok(char *str, char *del);
char *_strpbrk(char *s, char *accept);

/*string_operations.c*/
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
int _strncmp(const char *str1, const char *str2, size_t num);

#endif
