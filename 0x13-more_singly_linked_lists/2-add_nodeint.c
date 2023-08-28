#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning
 * of a listint_t list.
 * @head: Pointer to a pointer to the head
 * of the linked list.
 * @n: The value to be added to the new node.
 *
 * Return: Address of the new element
 * (the newly added node),
 * or NULL if memory allocation fails.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
