#include "main.h"

/**
 * leet - replaces characters in string
 * @str: array to whose characters to replace
 * Return: returns the edited array
 */

char *leet(char *str)
{
	int i;
	int length = strlen(str);
	char leetMap[256] = {0};

	leetMap['a'] = leetMap['A'] = '4';
	leetMap['e'] = leetMap['E'] = '3';
	leetMap['o'] = leetMap['O'] = '0';
	leetMap['t'] = leetMap['T'] = '7';
	leetMap['l'] = leetMap['L'] = '1';

	for (i = 0; i < length; i++)
	{
		if (leetMap[(unsigned char)str[i]])
		{
			str[i] = leetMap[(unsigned char)str[i]];
		}
	}

	return (str);
}
