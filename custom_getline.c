#include "monty.h"
/**
* resize_buffer - resizes the buffer
* @lineptr: store line read
* @n: buffer to be resized
* Return: void
*/
static void resize_buffer(char **lineptr, size_t *n)
{
	size_t i;
	size_t new_size = (*n) * 2;
	char *new_ptr = malloc(new_size);
	
	if (new_ptr == NULL)
	{
		exit(1);
	}
    
	for (i = 0; i < *n; i++)
	{
		new_ptr[i] = (*lineptr)[i];
	}
	free(*lineptr);
	*lineptr = new_ptr;
	*n = new_size;
}

/**
* custom_getline - getline function
* @lineptr: stores the line read
* @n: stores the size of buffer
* @stream: the file we are reading from
* Return: number of characters read
*/

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			exit(1);
		}
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF || c == '\n')
		{
			(*lineptr)[pos] = '\0';
			break;
		}
		(*lineptr)[pos] = (char)c;
		pos++;
		if (pos >= *n - 1)
		{
			resize_buffer(lineptr, n);
		}
	}
	if (c == EOF && pos == 0)
	{
		return (-1);
	}
	return ((ssize_t)pos);
}
