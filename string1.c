#include "shell.h"

/**
 * _strdup - string duplicated
 * @str: Original string contain the pointer
 *
 * Return: Duplicated string contain a pointer
 */
char *_strdup(char *str)
{
	char *A;
	unsigned int i;

	if (str == NULL)
		return (NULL);
	A = (char *)malloc(sizeof(char) * _strlen(str) + 1);

	if (A == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		A[i] = str[i];

	A[i] = '\0';
	return (A);
}

/**
 * _strcmp - Two strings compared
 * @s1: String contain the first pointer
 * @s2: String contain the second pointer
 * Return: Returns integer represents comparison result.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, rest = 1;

	for (i = 0; s2[i] != '\0'; i++)
	{
		rest = (s1[i] + '0') - (s2[i] + '0');

		if (rest != 0)
			break;
	}
	return (rest);
}


/**
 * _strcpy - the string pointed to by src is copied into dest
 * @dest: destination
 * @src: source
 * Return: char with copy of string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - Calcul length of null terminated string
 * @s: Calculate the length of pointer to the null terminated string
 *
 * Return: The length of the string (number of characters).
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strncmp - Compare the first 'n' characters of two strings
 * @str1: Compare the first string contain pointer
 * @str2: Compare the second string contain pointer
 * @n: maximum number of characters to compare
 *
 * Return: Integer <, =, or > than 0 if 'str1' is
 * was <, =, or >than 'str2', respectively.
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	unsigned char char1;
	unsigned char char2;

	while (n > 0 && *str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}

	if (n == 0)
	{
		return (0);
	}

	char1 = *(unsigned char *)str1;
	char2 = *(unsigned char *)str2;

	if (char1 < char2)
	{
		return (-1);
	}
	else if (char1 > char2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}