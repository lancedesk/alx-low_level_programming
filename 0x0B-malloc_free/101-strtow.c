#include "main.h"

/**
 * count_words - helper function
 * to count the number of words in a string
 * @str: string to evaluate
 * Return: number of words
 */

int count_words(char *str)
{
	int i, is_word = 0, word_count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!is_word)
			{
				is_word = 1;
				word_count++;
			}
		}
		else
		{
			is_word = 0;
		}
	}

	return (word_count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */

char **strtow(char *str)
{
	char **word_array, *temp_word;
	int i, word_index = 0, str_len = 0;
	int word_count = 0, temp_word_len = 0, start = 0, end = 0;

	while (str[str_len])
		str_len++;
	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);
	word_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word_array == NULL)
		return (NULL);
	for (i = 0; i <= str_len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (temp_word_len > 0)
			{
				end = i;
				temp_word = (char *)malloc(sizeof(char) * (temp_word_len + 1));
				if (temp_word == NULL)
					return (NULL);
				while (start < end)
					*temp_word++ = str[start++];

				*temp_word = '\0';
				word_array[word_index] = temp_word - temp_word_len;
				word_index++;
				temp_word_len = 0;
			}
		}
		else if (temp_word_len++ == 0)
		{
			start = i;
		}
	}
	word_array[word_index] = NULL;

	return (word_array);
}
