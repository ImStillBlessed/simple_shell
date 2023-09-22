#include "main.h"

/**
 *_strlen - counts
 *@s: string or smtg
 *Return: counter
 */

int _strlen(const char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

/**
 **_strcpy - copies
 *@src: source
 *@dest: destination
 *Return: returns
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 *_strdup - function returns pointer
 *@str: string to copied
 *Return: pointer to copied string
 */

char *_strdup(char *str)
{
	int n;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}
	n = _strlen(str) + 1;
	p = (char *)malloc(n * sizeof(char));
	if (p == NULL)
		return (NULL);
	_strcpy(p, str);
	return (p);
}

/**
 * _putchar - writes character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *printString - print strings
 *@str: pointer to string to printed
 */

void printString(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}

}
