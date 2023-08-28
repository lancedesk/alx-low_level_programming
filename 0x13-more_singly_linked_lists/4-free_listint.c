#include "lists.h"

/**
 * free_listint - Frees a list of integers.
 * @head: Pointer to the head of the list.
 *
 * This function deallocates the memory
 * occupied by each node
 * in the given linked list of integers.
 */

void free_listint(listint_t *head)
{
	listint_t *freed_list;

	while (head != NULL)
	{
		freed_list = head;
		head = head->next;
		free(freed_list);
	}
}
