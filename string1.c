#include "shell.h"

/**
 * _strcpy - it copy a string
 * @dest: Destination
 * @src: Source
 * Return: A pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strlen - It calculate the string's length.
 * @str: A pointer to the array's character.
 * Return: The string's length
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcat - It concatenate double strings
 * @dest: A pointer to the the string's destination
 * @src: A pointer to the string's source
 * Return: A pointer to the string dest's result
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int dest_len = _strlen(dest);
	int src_len = _strlen(src);

	for (i = 0; i < src_len; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strcmp - It compares two strings, end's at the first differing byte
 * @s1: The comparison should be made with the other string
 * @s2: The comparison should be made with the reference string
 * Return: Identify the first character where the two strings differ
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - It copy a string into a new buffer
 * @str: copy's the string
 * Return: New buffer pointe
 */
char *_strdup(const char *str)
{
	char *str_arr;
	unsigned int i;

	if (str == NULL)
		return (NULL);

	str_arr = (char *)malloc((strlen(str) + 1) * sizeof(char));

	if (!str_arr)
		return (NULL);
	i = 0;
	while (i < strlen(str))
	{
		str_arr[i] = str[i];
		i++;
	}
	str_arr[i] = '\0';

	return (str_arr);
}
