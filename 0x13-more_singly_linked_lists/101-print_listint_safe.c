#include "lists.h"

const listint_t **allocate_memory(
		const listint_t **list,
		size_t size,
		const listint_t *new
		);

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: Pointer to the start of the linked list.
 *
 * This function prints the elements of a linked list of type listint_t.
 * It does so in a safe manner to handle lists with loops. The function
 * goes through the list once and prints each node's address and value.
 * If a loop is detected, it prints the address and value of the looped
 * node, and returns the number of nodes traversed.
 *
 * Return: The number of nodes traversed in the linked list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t i, count = 0;
	const listint_t **printed_list = NULL;

	while (head != NULL)
	{
		for (i = 0; i < count; i++)
		{
			if (head == printed_list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(printed_list);
				return (count);
			}
		}
		count++;
		printed_list = allocate_memory(printed_list, count, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(printed_list);
	return (count);
}

/**
 * allocate_memory - Reallocates memory for an array of pointers
 * to nodes in a linked list.
 * @printed_list: Pointer to the old array of pointers.
 * @size: Size of the new array (one more than the old size).
 * @new: Pointer to the new node to be added.
 *
 * This function reallocates memory for a new array of pointers, copies the old
 * pointers to the new array, adds the new pointer to the end, and returns the
 * new array. If memory allocation fails, it frees the old array and exits with
 * status 98.
 *
 * Return: Pointer to the new array of pointers.
 */

const listint_t **allocate_memory(
		const listint_t **printed_list,
		size_t size,
		const listint_t *new
		)
{
	const listint_t **new_list;
	size_t i;

	new_list = malloc(size * sizeof(listint_t *));
	if (new_list == NULL)
	{
		free(printed_list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		new_list[i] = printed_list[i];
	new_list[i] = new;
	free(printed_list);
	return (new_list);
}
