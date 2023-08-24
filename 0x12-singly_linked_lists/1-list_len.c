#include "lists.h"

/**
 * list_len - Counts the number of elements in a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * This function counts the number of elements
 * in a linked list of type list_t.
 * It traverses the linked list and increments
 * the count for each element.
 * The final count of elements is returned.
 *
 * Return: The number of elements in the linked list.
 */

size_t list_len(const list_t *h)
{
	size_t total_number = 0;

	while (h != NULL)
	{
		total_number++;
		h = h->next;
	}

	return (total_number);
}
