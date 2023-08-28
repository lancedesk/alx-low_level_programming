#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * This function traverses the linked list
 * pointed to by @h and prints
 * the value of each node's 'n' member,
 * followed by a newline character.
 *
 * Return: The number of nodes in the linked list.
 */

size_t print_listint(const listint_t *h)
{
	size_t total_nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		total_nodes++;
		h = h->next;
	}

	return (total_nodes);
}
