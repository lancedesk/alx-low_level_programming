#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - Appends text to the end
 * of an existing file.
 *
 * @filename: The name of the file to which text
 * is appended.
 * @text_content: The text content to append
 * (can be NULL to do nothing).
 *
 * Return: On success, returns 1. On failure, returns -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written;
	size_t content_length;

	if (filename == NULL)
	{
		/* -1 for error if filename == NULL. */
		return (-1);
	}

	/* Open the filename file with flags to write */
	/* And flag to append & not create if != exists*/

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
	{
		/* -1 when the file can't be created or opened. */
		return (-1);
	}

	if (text_content != NULL)
	{
		/* Calculate length of the text_content string. */
		content_length = strlen(text_content);

		bytes_written = write(file_descriptor, text_content, content_length);

		if (bytes_written == -1 || (size_t)bytes_written != content_length)
		{
			close(file_descriptor);
			/* Return -1 to indicate a write error or failure. */
			return (-1);
		}
	}

	close(file_descriptor);
	/* Return 1 to indicate success. */
	return (1);
}

