#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node
 * at a given position in a list.
 * @head: Pointer to a pointer to the head node of the list.
 * @idx: Index at which the new node should be inserted.
 * @n: Value to be assigned to the new node.
 *
 * Return: Address of the new node, or NULL if insertion fails.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *inserted_node, *current_node;
	unsigned int index = 0;

	if (idx == 0)
	{
		inserted_node = malloc(sizeof(listint_t));
		if (inserted_node == NULL)
			return (NULL);

		inserted_node->n = n;
		inserted_node->next = *head;
		*head = inserted_node;
		return (inserted_node);
	}

	current_node = *head;

	while (current_node != NULL)
	{
		if (index == idx - 1)
		{
			inserted_node = malloc(sizeof(listint_t));
			if (inserted_node == NULL)
				return (NULL);

			inserted_node->n = n;
			inserted_node->next = current_node->next;
			current_node->next = inserted_node;
			return (inserted_node);
		}

		index++;
		current_node = current_node->next;
	}

	return (NULL);
}
