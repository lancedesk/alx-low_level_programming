#include "main.h"
#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints
 * it to the standard output.
 *
 * @filename: The name of the text file to read.
 * @letters: The maximum number of characters
 * to read and print.
 *
 * Return: On success, returns the actual
 * number of characters read and printed.
 * On failure, or if 'filename' is NULL, returns 0.
 * If any errors occur during file operations,
 * returns 0 as well.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descriptor;
	ssize_t printed_letters = 0, bytes_read;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}

	/* Open the filename file */
	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
	{
		return (0);
	}

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
	{
		/* Close the file before returning */
		close(file_descriptor);
		return (0);
	}

	bytes_read = read(file_descriptor, buffer, letters);

	if (bytes_read == -1)
	{
		close(file_descriptor);
		free(buffer);
		return (0);
	}

	printed_letters = write(STDOUT_FILENO, buffer, bytes_read);

	close(file_descriptor);
	free(buffer);
	return (printed_letters);
}

