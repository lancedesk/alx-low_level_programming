#include "lists.h"

/**
 * listint_len - Counts the number of elements
 * in a linked listint_t list.
 * @h: A pointer to the head of the linked list.
 *
 * This function traverses the linked list
 * pointed to by @h and counts
 * the number of elements (nodes) in the list.
 *
 * Return: The number of elements in the linked list.
 */

size_t listint_len(const listint_t *h)
{
	size_t list_len = 0;

	while (h != NULL)
	{
		list_len++;
		h = h->next;
	}

	return (list_len);
}
