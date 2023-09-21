#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define NOT_FOUND 127
#define PERMISSION_DENIED 126
#define EXIT_ERROR 2

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPE 2
#define NON_INTERACTIVE_MODE 0
#define ERROR -1
#define TOK_D " \t\r\n\a\""

/**
 * struct list_paths - a struct made for nodes out of environment variable path
 * @path: environment variable path
 * @len: length of the path
 * @next: points to the next node
 */

typedef struct list_paths
{
	char *path;
	unsigned int len;
	struct list_paths *next;
} list_paths;

extern char **environ;
list_paths *createPathList();
size_t printPathList(const list_paths *h);
void freePathList(list_paths *head);
list_paths *addPathNode(list_paths **head, char *path);
unsigned int custom_char_count(char *string, char character);
/*-----------*/

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int custom_atoi(char *s);
/*----------*/
void displayEnvironmentVariables(int *status);
int custom_determine_mode(int argc);
char *custom_check_access(char *line, list_paths *path_list);
char *getUserInput(list_paths *current);
void custom_free_resources(char **argv, char *command);
void custom_execute_command(char *path, char **av, char **env, int *status);
void scan_cmd_file(char *file);
char *custom_verify_file(char *file);
void freePathList(list_paths *head);
char **convert_line_to_array(char *line, int status);
char *intToString(int num);
void printErrorMessage(char *shell_name, int count,
		char *command_array, int type_of_error);
char *custom_get_status_string(int n);
char *custom_get_pid_string();
char *custom_getenv(const char *name);
int custom_builtin_handler(char *command, char **command_array
		, list_paths *current, char *shell_name, int count, int *status,
		list_paths *env_list, char **command_lines, char **argv);
void handleNonBuiltinCommand(char **command_array, char *env[], int *status,
		int count, list_paths *current, char *argv[]);
int custom_change_directory(char **command_array, char **argument_vector);
void custom_set_environment_variable(char *key, char *value,
		list_paths *current);
char **processCommandFiles(int op_mode, char *file_name, char *shell_name);
char **processShellCommandsFromFile(char *file_name, char *shell_name);
int custom_directory_check(char *command, char **argument_vector, int count,
		char **command_array, int *status, char *command_line_before);
char *intToString(int number);
char **text_to_array(char *text_read);
void custom_file_open_handler(char *program_name, int counter
		, char *file_name);
unsigned int countCharacterOccurrences(char *string, char c);
char **processShellCommandsPipes();
char *get_non_interactive_command(char **command_lines, int count);
void permission_handler(char **command_array, int count,
		char *executable, int *status, char *command);
void process_command(char *command, int *status, char ***command_array);
int count_lines(char *line);
char **allocate_vector(int size);
void custom_free_string_vector(char **vector);
char *processToken(char *token, int status);
int tokenize_command(char *command, int status, char **argument_vector);
char *handle_flags(char *token, char *command,
		char **argument_vector, int status);
char *custom_strtok(char *str, const char *delimiters);
void custom_free_everything(char **command_lines, int count, list_paths *env,
		list_paths *current, char *command, char **command_array);
void custom_exit_handler(char *command, char **command_array
		, list_paths *current, char *shell_name, int count, int *status,
		list_paths *env, char **command_lines);
void remove_comments(char *input);

#endif

