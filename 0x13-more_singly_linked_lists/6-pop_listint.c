#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t
 * linked list.
 * @head: A pointer to a pointer to the head node.
 * Return: The data (n) of the deleted head node,
 * or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	int node_data;
	listint_t *temp;

	if (*head == NULL)
	{
		return (0);
	}

	/* Store the data of the current head */
	node_data = (*head)->n;
	/* Store the current head node */
	temp = *head;
	/* Update the head to point to the next node */
	*head = (*head)->next;
	/* Free the old head node */
	free(temp);
	/* Return the data of the old head node */
	return (node_data);
}

