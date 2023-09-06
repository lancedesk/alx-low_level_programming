#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_error(const char *message);
void display_elf_header_info(const char *filename);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, or the appropriate exit code on failure.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		display_error("Usage: elf_header elf_filename");
	}

	display_elf_header_info(argv[1]);

	return (0);
}

/**
 * display_error - Display an error message
 * to standard output.
 * @message: The error message to display.
 *
 * This function takes an error message as input
 * and displays it to the standard
 * output using the printf function.
 */

void display_error(const char *message)
{
	dprintf(1, "%s\n", message);
	exit(98);
}

/**
 * display_elf_header_info - Display information
 * from the ELF header of a file.
 * @filename: The name of the ELF file to examine.
 */

void display_elf_header_info(const char *filename)
{
	int file_descriptor, i, ei_class, ei_data;
	Elf64_Ehdr header;
	char *os_abi;

	/* Open the ELF file */
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
	{
		display_error("Error: Unable to open file");
	}

	/* Read the ELF header */
	if (read(file_descriptor, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		display_error("Error: Unable to read ELF header");
	}

	/* Display ELF header information */
	dprintf(1, "ELF Header:\n");
	dprintf(1, "  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		dprintf(1, "%02x ", header.e_ident[i]);
	}

	dprintf(1, "\n");
	ei_class = (header.e_ident[EI_CLASS] == ELFCLASS32);
	ei_data = (header.e_ident[EI_DATA] == ELFDATA2LSB);

	dprintf(1, "  Class:                             ELF%d\n", ei_class ? 32 : 64);
	dprintf(1, "  Data:                              2's complement, %s endian\n", ei_data ? "little" : "big");
	dprintf(1, "  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);

	switch (header.e_ident[EI_OSABI])
	{
		case 0:
			os_abi = "System V";
			break;
		case 6:
			os_abi = "Solaris";
			break;
		default:
			os_abi = "Unknown";
			break;
	}

	dprintf(1, "  OS/ABI:                            UNIX - %s\n", os_abi);
	dprintf(1, "  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	dprintf(1, "  Type:                              EXEC (Executable file)\n");
	dprintf(1, "  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);
	dprintf(1, "0\n");
}

