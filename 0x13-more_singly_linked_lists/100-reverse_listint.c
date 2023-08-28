#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Pointer to a pointer to the head node of the list.
 *
 * Return: A pointer to the first node of the reversed list.
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous, *current;

	previous = NULL;
	current = *head;

	while (current != NULL)
	{
		*head = current->next;
		current->next = previous;
		previous = current;
		current = *head;
	}

	*head = previous;

	return (*head);
}

