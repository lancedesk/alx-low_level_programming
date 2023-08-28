#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node
 * of a listint_t linked list.
 * @head: Pointer to the head node of the linked list.
 * @index: Index of the node to retrieve (starting from 0).
 *
 * Return: Pointer to the nth node, or NULL
 * if the node does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *node_pointer;

	node_pointer = head;

	while (node_pointer != NULL)
	{
		if (count == index)
		{
			return (node_pointer);
		}
		count++;
		node_pointer = node_pointer->next;
	}

	return (NULL);
}

