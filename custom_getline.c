#include "main.h"

/**
 * malloc_usable_size - malloc
 * @ptr: pointer
 * Return: Pointer.
 */

size_t malloc_usable_size(const void *ptr)
{
	size_t *size_ptr;

	if (ptr == NULL)
		return (0);

	size_ptr = (size_t *)ptr - 1;
	return (*size_ptr);
}

/**
 * _getc - a fucntion checks if it's end of line or not
 * @stream: the stream
 * Return: either 0 o 1
 */

int _getc(FILE *stream)
{
	char ch;
	ssize_t bytes_read = read(fileno(stream), &ch, 1);

	return ((bytes_read == 1) ? ch : EOF);
}
/**
 * _realloc - a fucntion realocate memory
 * @ptr: string we are relocating
 * @size: new allocation
 * Return: new realocated memory
 */

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t original_size, copy_size;

	if (ptr == NULL)
		return (malloc(size));


	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);

	original_size = malloc_usable_size(ptr);
	copy_size = (original_size < size) ? original_size : size;
	_memcpy(new_ptr, ptr, copy_size);

	free(ptr);

	return (new_ptr);
}
/**
 * _getline - takes ipnut from user
 * @lineptr: adress of input
 * @n: buffer
 * @stream: STDIN
 * Return: either 0 or -1
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t len = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL)
		*n = 0;
	while ((ch = _getc(stream)) != EOF)
	{
		if (len + 1 >= *n)
		{
			*n += 1024 * 8;
			new_lineptr = _realloc(*lineptr, *n);
			if (new_lineptr == NULL)
			return (-1);
			*lineptr = new_lineptr;
		}
		(*lineptr)[len++] = ch;
		if (ch == '\n')
		break;
	}
	if (len == 0 || ch == EOF)
		return (-1);
	(*lineptr)[len] = '\0';
	return (len);
}

/**
 *_getenv - gets value of variable
 *@var: variable
 *Return: pointer to variable value
*/

char *_getenv(char *var)
{
	size_t len = _strlen(var);
	char **env = environ;

	if (var == NULL)
		return (NULL);
	for (; *env != NULL; env++)
	{
		if (_strncmp(*env, var, len) == 0 && (*env)[len] == '=')
			return (*env + len + 1);
	}
	return (NULL);
}
