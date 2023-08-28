#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Double pointer to the start of the list.
 *
 * Return: The number of nodes traversed in the linked list.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}

	current = *h;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;

		if (next >= current)
		{
			break;
		}

		current = next;
	}

	*h = NULL;
	return (count);
}

