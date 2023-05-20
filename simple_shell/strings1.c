#include "main.h"
/* strdup */ 
char *_strdup(const char *s)
{
    char *str;
    size_t len;

    len = _strlen(s);
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    _memcpy(str, s, len + 1);
    return (str);
}
/* strlen */ 
int _strlen(const char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;
    return (len);
}
/* memcpy */ 
void *_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    char *dest_ptr = (char *)dest;
    const char *src_ptr = (const char *)src;

    for (i = 0; i < n; i++)
        dest_ptr[i] = src_ptr[i];

    return (dest);
}
/**
 * _strcat - Concatenates two strings
 * @newstr: The destination string
 * @str: The source string
 *
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *newstr, const char *str)
{
    char *ptr = newstr;

    while (*ptr != '\0')
        ptr++;

    while (*str != '\0')
    {
        *ptr = *str;
        ptr++;
        str++;
    }

    *ptr = '\0';

    return newstr;
}
/**
 * *_strcpy - Copies this string pointed to by src.
 * @newstr: Type char pointer the dest of the copied str
 * @str: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *newstr, char *str)
{

	size_t n;

	for (n = 0; str[n] != '\0'; n++)
	{
		newstr[n] = str[n];
	}
	newstr[n] = '\0';

	return (newstr);
}