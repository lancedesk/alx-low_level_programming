#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to a pointer to the head of the list
 * @n: integer value to be added to the new node
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		/* Memory allocation failed */
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		/* If the list is empty, new node becomes the head */
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		/* Traverse the list to find the last node */
		dlistint_t *temp = *head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		/* Add the new node at the end of the list */
		temp->next = new_node;
		new_node->prev = temp;
	}

	return (new_node);
}

