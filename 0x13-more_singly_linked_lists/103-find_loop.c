#include "lists.h"

/**
 * find_listint_loop - Finds the start of a loop in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: Address of the node where the loop starts,
 * or NULL if no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	tortoise = hare = head;

	while (tortoise != NULL && hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		/* Meeting point found, loop detected */
		if (tortoise == hare)
		{
			/* Move tortoise to head */
			tortoise = head;

			/* Move tortoise and hare at same speed, */
			/* they will meet at loop start*/
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}

			/* Return the node where the loop starts */
			return (tortoise);
		}
	}

	/* No loop found */
	return (NULL);
}

