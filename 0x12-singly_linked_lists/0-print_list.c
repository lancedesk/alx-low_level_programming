#include "main.h"

/**
 * print_list - Prints the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * This function prints the elements of a linked list
 * of type list_t. Each element
 * in the linked list is printed with its associated
 * length and string value.
 * If the provided linked list is NULL,
 * the function prints "[0] (nil)".
 *
 * Return: The number of nodes in the linked list.
 */

size_t print_list(const list_t *h)
{
	size_t total_size = 0;

	if (h == NULL)
	{
		/* Print the format with newline */
		printf("[0] (nil)\n");

		/* Return 0 since there are no nodes */
		return (0);
	}

	/* Loop through the linked list */
	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			/* Print the length and string */
			printf("[%d] %s\n", h->len, h->str);
		}
		/* Increment total_size for each node */
		total_size++;

		/* Move to the next node */
		h = h->next;
	}

	/* Return the total number of nodes */
	return (total_size);
}
