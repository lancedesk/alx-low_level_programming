#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created sorted hash table, or NULL on failure.
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts a key-value pair into a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 * @value: The value.
 *
 * Return: 1 if successful, 0 otherwise.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *temp, *prev;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	temp = ht->shead;
	prev = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (0);
			return (1);
		}
		if (strcmp(temp->key, key) > 0)
			break;
		prev = temp;
		temp = temp->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->snext = temp;
	new_node->sprev = prev;

	if (prev != NULL)
		prev->snext = new_node;
	else
		ht->shead = new_node;

	if (temp != NULL)
		temp->sprev = new_node;
	else
		ht->stail = new_node;

	return (1);
}

/**
 * shash_table_get - Retrieves value associated with a key
 * in a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	temp = ht->shead;
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->snext;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	temp = ht->shead;
	while (temp != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		first = 0;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	temp = ht->stail;
	while (temp != NULL)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		first = 0;
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp;

	if (ht == NULL)
		return;

	temp = ht->shead;
	while (temp != NULL)
	{
		free(temp->key);
		free(temp->value);
		ht->shead = temp->snext;
		free(temp);
		temp = ht->shead;
	}

	free(ht->array);
	free(ht);
}

