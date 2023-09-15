#include "shell.h"


ssize_t cat(const char *name)
{
	FILE *file;
	char buffer[1024];
	size_t bytes;

	file = fopen(name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Failed to Read from file %s\n", name);
		return (-1);
	}
	bytes = fread(buffer, 1, 1024, file);
	if (bytes > 0)
		fwrite(buffer, 1, bytes, stdout);
	fclose(file);
	return (bytes);
}
