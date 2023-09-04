#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int cp(const char *file_from, const char *file_to);

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success, or the appropriate exit code on failure.
 */

int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	if (cp(av[1], av[2]) == -1)
		return (98);

	return (0);
}

/**
 * cp - Copies the content of a file to another file
 * @file_from: The source file
 * @file_to: The destination file
 * Return: 0 on success, or -1 on failure.
 */

int cp(const char *file_from, const char *file_to)
{
	int source_fd, dest_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[1024];
	mode_t file_permissions = S_IWUSR | S_IRUSR | S_IROTH | S_IRGRP | S_IWGRP;

	source_fd = open(file_from, O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	dest_fd = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, file_permissions);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(source_fd);
		exit(99);
	}

	while ((bytes_read = read(source_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(source_fd);
			close(dest_fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(source_fd);
		close(dest_fd);
		exit(98);
	}

	if (close(source_fd) == -1 || close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}

	return (0);
}

