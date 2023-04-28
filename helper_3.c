#include "shell.h"

/**
 * my_memcpy - my_mem
 * @dest: dest
 * @src: src
 * @n: n
 * Return: return
 */
void *my_memcpy(void *dest, const void *src, size_t n)
{
	char *pdest = dest;
	const char *psrc = src;
	size_t i;

	for (i = 0; i < n; i++)
	{
		pdest[i] = psrc[i];
	}
	return (dest);
}

/**
 * my_realloc - allocates memory from heap
 * @ptr: pointer 
 * @size: size
 * Return: return
 */
void *my_realloc(void *ptr, size_t size)
{
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (ptr == NULL)
	{
		return (malloc(size));
	}
	else
	{
		void *new_ptr = malloc(size);

		if (new_ptr == NULL)
		{
			return (NULL);
		}
		my_memcpy(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
}

/**
 * printenv -  env
 * Return: value on succesful termination
 */
int printenv(void)
{
	int i = 0;

	while ((environ[i]))
	{
		printString(environ[i]);
		printString("\n");
		i++;
	}

	return (0);
}
