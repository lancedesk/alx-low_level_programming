#include "lists.h"

/**
 * add_node - Adds a new node at the beginning of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @str: The string to be duplicated and stored in the new node.
 *
 * Return: The address of the new element (new head),
 * or NULL if memory allocation fails.
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = (list_t *)malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		/* Return NULL if memory allocation fails */
		return (NULL);
	}

	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		/* Free allocated node if strdup fails */
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);

	/* Update next to point to the old head */
	new_node->next = *head;

	/* Update head to point to the new node */
	*head = new_node;

	return (new_node);
}
