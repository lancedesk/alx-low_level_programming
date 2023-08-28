#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node
 * at a given index of a listint_t linked list.
 * @head: Pointer to a pointer to the head node of the list.
 * @index: Index of the node to be deleted.
 *
 * Return: 1 if deletion succeeded, -1 if it failed.
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node, *current_node;
	unsigned int i;


	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);

		return (1);
	}

	prev_node = *head;
	current_node = (*head)->next;

	for (i = 1; i < index && current_node != NULL; i++)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}

	if (current_node == NULL)
	{
		return (-1);
	}

	prev_node->next = current_node->next;

	free(current_node);

	return (1);
}
