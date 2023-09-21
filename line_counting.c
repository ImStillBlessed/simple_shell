/**
 * count_lines - Counts the number of lines in a given string.
 * @input_string: The input string.
 * Return: The number of lines in the string.
 */
int count_lines(char *input_string)
{
	int line_count = 0;

	while (*input_string != '\0')
	{
		line_count++;
		input_string++;
	}

	return (line_count);
}

