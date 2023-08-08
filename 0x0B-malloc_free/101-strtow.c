#include "main.h"

/**
 * strtow - returns a pointer to
 * an array of strings (words)
 * @str: string to be split
 * Return: pointer to an array
 * of strings (words)
 */

char **strtow(char *str)
{
	char **finalstring;
	int num_words;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	num_words = count_words(str);

	if (num_words == 0)
		return (NULL);

	finalstring = allocate_and_fill(str, num_words);

	if (finalstring == NULL)
		return (NULL);

	return (finalstring);
}

/**
 * allocate_and_fill - allocates memory and
 * fills the finalstring array with words
 * @str: string to be split
 * @num_words: number of words
 * Return: pointer to the filled array
 */

char **allocate_and_fill(char *str, int num_words)
{
	int i, length, word_index = 0, start = -1;
	char **finalstring = (char **)malloc((num_words + 1) * sizeof(char *));

	if (finalstring == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (start == -1)
				start = i;
		}
		else
		{
			if (start != -1)
			{
				length = i - start;
				finalstring[word_index] = create_word(str, start, length);
				if (finalstring[word_index] == NULL)
				{
					free_and_copy_memory(finalstring, word_index, str, start, length);
					return (NULL);
				}
				word_index++;
				start = -1;
			}
		}
	}
	if (start != -1)
	{
		length = strlen(str) - start;
		finalstring[word_index] = create_word(str, start, length);
		if (finalstring[word_index] == NULL)
		{
			free_and_copy_memory(finalstring, word_index, str, start, length);
			return (NULL);
		}
	}
	finalstring[word_index] = NULL;
	return (finalstring);
}

/**
 * create_word - creates a new word and copies data into it
 * @src: source string
 * @start: start of string
 * @length: length of string
 * Return: pointer to the new word
 */

char *create_word(char *src, int start, int length)
{
	char *word = (char *)malloc((length + 1) * sizeof(char));

	if (word == NULL)
		return (NULL);

	strncpy(word, src + start, length);
	word[length] = '\0';
	return (word);
}

/**
 * count_words - counts words in string
 * @str: string to be counted
 * Return: number of words in string
 */

int count_words(char *str)
{
	int count = 0, is_word = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			if (!is_word)
			{
				count++;
				is_word = 1;
			}
		}
		else
		{
			is_word = 0;
		}
	}

	return (count);
}

/**
 * free_and_copy_memory - frees memory and copies words from string to string
 * @finalstring: final string
 * @word_index: word index
 * @src: source string
 * @start: start of string
 * @length: length of string
 */

void free_and_copy_memory(
		char **finalstring,
		int word_index,
		char *src,
		int start,
		int length
		)
{
	int j;
	char *dest;

	for (j = 0; j < word_index; j++)
	{
		free(finalstring[j]);
	}

	free(finalstring);

	dest = (char *)malloc((length + 1) * sizeof(char));

	if (dest != NULL)
	{
		strncpy(dest, src + start, length);
		dest[length] = '\0';
	}
}

