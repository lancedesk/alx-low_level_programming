#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end
 * of a listint_t list.
 * @head: Pointer to a pointer to the head
 * of the linked list.
 * @n: The value to be added to the new node.
 *
 * This function creates a new node with
 * the given value @n and adds it to
 * the end of the linked list pointed to by @head.
 *
 * Return: Address of the new element
 * (the newly added node),
 * or NULL if memory allocation fails.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *current_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}

	return (new_node);
}
