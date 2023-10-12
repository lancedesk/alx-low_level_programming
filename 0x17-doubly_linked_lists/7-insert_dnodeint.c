#include "lists.h"

static dlistint_t *create_dnodeint(int n);

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to a pointer to the head of the list
 * @idx: index where the new node should be added (starting from 0)
 * @n: integer value for the new node
 * Return: pointer to the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int count;
	dlistint_t *new_node, *temp;

	new_node = create_dnodeint(n);
	if (new_node == NULL)
	{
		return (NULL); /* Allocation failed */
	}

	if (idx == 0)
	{
		new_node->next = *h; /* Insert at the beginning of the list */
		if (*h != NULL)
		{
			(*h)->prev = new_node;
		}
		*h = new_node;
	}
	else
	{
		temp = *h;
		count = 0;

		while (count < idx - 1)
		{
			if (temp == NULL)
			{
				free(new_node); /* Invalid index, free the allocated node */
				return (NULL);
			}
			temp = temp->next;
			count++;
		}

		new_node->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next->prev = new_node;
		}
		temp->next = new_node;
		new_node->prev = temp;
	}

	return (new_node);
}

/**
 * create_dnodeint - creates a new dlistint_t node
 * @n: integer value for the new node
 * Return: pointer to the new node, or NULL if it failed
 */

static dlistint_t *create_dnodeint(int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
	{
		return (NULL); /* Allocation failed */
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

