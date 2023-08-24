#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @str: The string to be duplicated and stored in the new node.
 *
 * Return: The address of the new element (new last node),
 * or NULL if memory allocation fails.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *last_node, *current_node;

	last_node = (list_t *)malloc(sizeof(list_t));

	if (last_node == NULL)
	{
		return (NULL);
	}

	last_node->str = strdup(str);

	/* Set the new node's next to NULL */
	last_node->next = NULL;

	if (*head == NULL)
	{
		*head = last_node;
	}
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = last_node;
	}

	return (last_node);
}
