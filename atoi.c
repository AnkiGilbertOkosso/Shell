#include "shell.h"

/**
 * is_interactive - checks if the shell is  in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(fileno(atdin)) && info->readfd <= 2);
}
/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delimiter: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delimiter)
{
	while (*delimiter)
	{
		if (c == *delimiter++)
			return (1);
	}
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: the character input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _myatoi - converts a string to an integer
 * @s: the string to be converted
 * Return: ) if there's no number in the string, otherwise converted number
 */
int _myatoi(char *s)
{
	int i = 0, sign = 1, result = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i = 1;
	}

	for (; s[i] != '\0'; ++i)
	{
		if (s[i] < '0' || s[i]i > '9')
			break;
		result = result * 10 + (s[i] - '0');
	}
	return (sign * result);
}
