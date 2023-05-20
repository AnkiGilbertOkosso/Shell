#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */
int _atoi(char *str)
{
    int sign = 1; // sign of the number
    int result = 0; // converted number
    int i = 0; // index

    // Handle leading whitespace
    while (str[i] == ' ')
        i++;

    // Handle the sign
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to number
    while (str[i] >= '0' && str[i] <= '9') {
        result = (result * 10) + (str[i] - '0');
        i++;
    }

    return (sign * result);
}
/**
 * int_to_string - function that converts int to string.
 * @num: type of int number
 * Return: String.
 */
char *int_to_string(int num) 
{
    int len = 0;
    int n = num;
    int sign = 0;

    if (n < 0) {
        sign = 1;
        n = -n;
    }
    while (num != 0) {
        len++;
        num /= 10;
    }
    if (sign) {
        len++;
    }
    char* str = (char*)malloc((len + 1) * sizeof(char));
    int i = len - 1;
    while (n != 0) {
        str[i] = '0' + (n % 10);
        n /= 10;
        i--;
    }
    if (sign) {
        str[0] = '-';
    }
    str[len] = '\0';

    return (str);
}


/**
 * get_len - Get lenghts of a number.
 * @num: type of int number.
 * Return: Lenght of number.
 */
int get_len(int num)
{
	unsigned int n;
	int len = 1;

	if (num < 0)
	{
		len++;
		n = num * -1;
	}
	else
	{
		n = num;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}

	return (len);
}
/**
 * _strtok - splits the string by some delimiter.
 * @str: input string.
 * @delimiter: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delimiter)
{
    static char* saveptr = NULL;
    char* token;
    int i, j;
    int str_len = _strlen(str);
    int delimiter_len = _strlen(delimiter);

    if (str != NULL)
        saveptr = str;
    if (saveptr == NULL || *saveptr == '\0')
        return NULL;
    while (*saveptr != '\0' && _strchr(delimiter, *saveptr) != NULL)
        saveptr++;
    if (*saveptr == '\0')
        return NULL;
    token = saveptr;
    while (*saveptr != '\0' && _strchr(delimiter, *saveptr) == NULL)
        saveptr++;
    if (*saveptr == '\0')
        saveptr = NULL;
    else
        *saveptr++ = '\0';
    while (*token != '\0' && _strchr(delimiter, *token) != NULL)
        token++;

    j = _strlen(token) - 1;
    while (j >= 0 && _strchr(delimiter, token[j]) != NULL)
        token[j--] = '\0';
    return token;
}
/**
 * _charscmp - compare chars of the strings
 * @str: input string.
 * @delimiter: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int _charscmp(char str[], const char *delimiter)
{
    unsigned int i, j, match_count;

    for (i = 0, match_count = 0; str[i]; i++)
    {
        for (j = 0; delimiter[j]; j++)
        {
            if (str[i] == delimiter[j])
            {
                match_count++;
                break;
            }
        }
    }

    if (i == match_count)
        return 1;
    return 0;
}
