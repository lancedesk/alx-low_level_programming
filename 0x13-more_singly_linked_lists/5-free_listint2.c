#include "lists.h"

/**
 * free_listint2 - Frees a list of integers
 * and sets the head to NULL.
 * @head: Pointer to the head of the list.
 *
 * This function deallocates the memory
 * occupied by each node
 * in the given linked list of integers
 * and sets the head to NULL.
 */

void free_listint2(listint_t **head)
{
	listint_t *freed_list, *temporary;

	if (*head == NULL)
	{
		return;
	}

	freed_list = *head;

	while (freed_list != NULL)
	{
		temporary = freed_list;
		freed_list = temporary->next;
		free(temporary);
	}

	*head = NULL;
	head = NULL;
}
