#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at a given position
 * @head: pointer to a pointer to the head of the list
 * @index: index of the node that should be deleted (starting from 0)
 * Return: 1 if succeeded, -1 if failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *prev;
	unsigned int count = 0;

	if (*head == NULL)
	{
		return (-1); /* Empty list */
	}
	temp = *head;

	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(temp);
		return (1);
	}

	while (temp != NULL && count < index)
	{
		prev = temp;
		temp = temp->next;
		count++;
	}

	if (count == index && temp != NULL)
	{
		prev->next = temp->next;
		if (temp->next != NULL)
		{
			temp->next->prev = prev;
		}
		free(temp);
		return (1);
	}

	return (-1); /* Invalid index */
}

