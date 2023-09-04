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

int main(int argc, char *argv[]) {
	if (argc != 2) {
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

void display_error(const char *message) {
	dprintf(1, "%s\n", message);
	exit(98);
}

/**
 * display_elf_header_info - Display information
 * from the ELF header of a file.
 * @filename: The name of the ELF file to examine.
 */

void display_elf_header_info(const char *filename) {
	int file_descriptor, ei_class, ei_data, i;
	Elf64_Ehdr header;

	/* Open the ELF file */
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1) {
		display_error("Error: Unable to open file");
	}

	/* Read the ELF header */
	if (read(file_descriptor, &header, sizeof(Elf64_Ehdr)) !=
			sizeof(Elf64_Ehdr)) {
		display_error("Error: Unable to read ELF header");
	}

	/* Check for ELF magic number */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3) {
		display_error("Error: Not an ELF file");
	}

	/* Display ELF header information */
	dprintf(1, "Magic: ");
	for (i = 0; i < EI_NIDENT; i++) {
		dprintf(1, "%02x ", header.e_ident[i]);
	}

	ei_class = (header.e_ident[EI_CLASS] == ELFCLASS32);
	ei_data = (header.e_ident[EI_DATA] == ELFDATA2LSB);

	dprintf(1, "\nClass: %d-bit\n", ei_class ? 32 : 64);
	dprintf(1, "Data: %s-endian\n", ei_data ? "little" : "big");
	dprintf(1, "Version: %d\n", header.e_ident[EI_VERSION]);
	dprintf(1, "OS/ABI: %d\n", header.e_ident[EI_OSABI]);
	dprintf(1, "ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	dprintf(1, "Type: %d\n", header.e_type);
	dprintf(1, "Entry point address: 0x%lx\n", (unsigned long)header.e_entry);
}

