#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */
int _atoi(char *str)
{
    int sign = 1; 
    int result = 0; 
    int i = 0; 

    while (str[i] == ' ')
        i++;

    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }

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
    int sign = 0, i;
    char *str;

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
    str = (char*)malloc((len + 1) * sizeof(char));
    i = len - 1;
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
	char *start;
	static char *div, *end;
	unsigned int i, n;

	if (str != NULL)
	{
		if (_charscmp(str, delimiter))
			return (NULL);
		div = str; /*Stores first address*/
		i = _strlen(str);
		end = &str[i]; /*Stores last address*/
	}
	start = div;
	if (start == end) /*Reaching the ends*/
		return (NULL);

	for (n = 0; *div; div++)
	{
		/*Breaking loops finding the next token*/
		if (div != start)
			if (*div && *(div - 1) == '\0')
				break;
		/*Replacing delimiter for the null char*/
		for (i = 0; delimiter[i]; i++)
		{
			if (*div == delimiter[i])
			{
				*div = '\0';
				if (div == start)
					start++;
				break;
			}
		}
		if (n == 0 && *div) /*Str != Delim*/
			n = 1;
	}
	if (n == 0) /*Str == Delim*/
		return (NULL);
	return (start);
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
