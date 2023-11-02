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
	{
		return (NULL);
	}

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ht->array[i] = NULL;
	}
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
	shash_node_t *new_value, *temporary;
	char *copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	copy = strdup(value);
	if (copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temporary = ht->shead;
	while (temporary)
	{
		if (strcmp(temporary->key, key) == 0)
		{
			free(temporary->value);
			temporary->value = copy;
			return (1);
		}
		temporary = temporary->snext;
	}

	new_value = malloc(sizeof(shash_node_t));
	if (new_value == NULL)
	{
		free(copy);
		return (0);
	}
	new_value->key = strdup(key);
	if (new_value->key == NULL)
	{
		free(copy);
		free(new_value);
		return (0);
	}
	new_value->value = copy;
	new_value->next = ht->array[index];
	ht->array[index] = new_value;

	if (ht->shead == NULL)
	{
		new_value->sprev = NULL;
		new_value->snext = NULL;
		ht->shead = new_value;
		ht->stail = new_value;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_value->sprev = NULL;
		new_value->snext = ht->shead;
		ht->shead->sprev = new_value;
		ht->shead = new_value;
	}
	else
	{
		temporary = ht->shead;
		while (temporary->snext != NULL && strcmp(temporary->snext->key, key) < 0)
			temporary = temporary->snext;
		new_value->sprev = temporary;
		new_value->snext = temporary->snext;
		if (temporary->snext == NULL)
			ht->stail = new_value;
		else
			temporary->snext->sprev = new_value;
		temporary->snext = new_value;
	}

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
	shash_node_t *table_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
	{
		return (NULL);
	}

	table_node = ht->shead;
	while (table_node != NULL && strcmp(table_node->key, key) != 0)
	{
		table_node = table_node->snext;
	}

	return ((table_node == NULL) ? NULL : table_node->value);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *table_node;

	if (ht == NULL)
		return;

	table_node = ht->shead;
	printf("{");
	while (table_node != NULL)
	{
		printf("'%s': '%s'", table_node->key, table_node->value);
		table_node = table_node->snext;
		if (table_node != NULL)
		{
			printf(", ");
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *table_node;

	if (ht == NULL)
	{
		return;
	}

	table_node = ht->stail;
	printf("{");
	while (table_node != NULL)
	{
		printf("'%s': '%s'", table_node->key, table_node->value);
		table_node = table_node->sprev;
		if (table_node != NULL)
		{
			printf(", ");
		}
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *table_node, *temporary;

	if (ht == NULL)
	{
		return;
	}

	table_node = ht->shead;
	while (table_node)
	{
		temporary = table_node->snext;
		free(table_node->key);
		free(table_node->value);
		free(table_node);
		table_node = temporary;
	}

	free(head->array);
	free(head);
}
