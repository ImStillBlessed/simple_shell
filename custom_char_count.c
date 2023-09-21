/**
 *custom_char_count - Counts the occurrences of a specific character in string.
 * @input_string: The input string.
 * @target_character: The character to count.
 * Return: The number of occurrences of the character in the string.
 */
unsigned int custom_char_count(char *input_string, char target_character)
{
	unsigned int occurrence_count = 0;

	while (*input_string != '\0')
	{
		if (*input_string != target_character &&
				*(input_string + 1) == target_character)
			occurrence_count++;
		input_string++;
	}
	return (occurrence_count + 1);
}
