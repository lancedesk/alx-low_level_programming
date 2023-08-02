#include "main.h"

/**
 * is_palindrome_recursive - helper palindrome function
 * @left: left string pointer
 * @right: right string pointer
 *
 * Return: 1 if prime, 0 if not
 */

int is_palindrome_recursive(char *left, char *right)
{
	/* Base case: If the pointers meet or cross each */
	/* other, it means the string is a palindrome */

	if (left >= right)
	{
		return (1);
	}

	/* Recursive case: If the characters at the left */
	/* and right pointers are equal, continue checking the rest */

	if (*left == *right)
	{
		return (is_palindrome_recursive(left + 1, right - 1));
	}

	return (0);
}

/**
 * is_palindrome - function to check if string is palindrome
 * @s: string to check
 * Return: 0 if not palindrome and 1 if is
 */

int is_palindrome(char *s)
{
	int length = strlen(s);

	if (length == 0)
	{
		return (1);
	}

	return (is_palindrome_recursive(s, s + length - 1));
}
