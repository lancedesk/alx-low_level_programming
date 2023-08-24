#include "lists.h"

/**
 * free_list - Frees a linked list_t list.
 * @head: A pointer to the head of the linked list.
 *
 * This function deallocates the memory occupied by each node
 */

void free_list(list_t *head)
{
	list_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;

		/* Free the string within the node */
		free(current_node->str);

		/* Free the node itself */
		free(current_node);
	}
}
