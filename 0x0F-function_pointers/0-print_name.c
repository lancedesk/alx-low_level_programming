#include "function_pointers.h"

/**
 * print_name - prints name
 * @name: name to print
 * @f: function as parameter
 */

void print_name(char *name, void (*f)(char *))
{
	void (*name_as_is)(char *);
	void (*in_caps)(char *);

	if (name == NULL || f == NULL)
	{
		return;
	}

	if (f == print_name_as_is)
	{
		name_as_is = print_name_as_is;
		name_as_is(name);
	}

	else
	{
		in_caps = print_name_uppercase;
		in_caps(name);
	}
}
