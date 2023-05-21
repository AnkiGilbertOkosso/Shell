#include "main.h"

/**
 * _cd - changes the current directory
 *
 * @data: relevant data
 * Return: 1 on success
 */
int _cd(runtime_data *data)
{
    char *directory;
    int is_home, is_home1, is_dash;

    directory = data->tokens[1];

    if (directory != NULL)
    {
        is_home = _strcmp("$HOME", directory);
        is_home1 = _strcmp("~", directory);
        is_dash = _strcmp("--", directory);
    }

    if (directory == NULL || !is_home || !is_home1 || !is_dash)
    {
        cd_home(data);
        return (1);
    }

    if (_strcmp("-", directory) == 0)
    {
        cd_prev(data);
        return (1);
    }

    if (_strcmp(".", directory) == 0 || _strcmp("..", directory) == 0)
    {
        cd_parent(data);
        return (1);
    }

    cd_to(data);

    return (1);
}

/**
 * __exit - exits the shell
 *
 * @data: relevant data (status and tokens)
 * Return: 0 on success
 */
int __exit(runtime_data *data)
{
    int large_number, str_len, is_digit;
    unsigned int exit_status;

    if (data->tokens[1] != NULL)
    {
        exit_status = _atoi(data->tokens[1]);
        is_digit = _isdigit(data->tokens[1]);
        str_len = _strlen(data->tokens[1]);
        large_number = exit_status > (unsigned int)INT_MAX;
        if (!is_digit || str_len > 10 || large_number)
        {
            get_error(data, 2);
            data->status = 2;
            return (1);
        }
        data->status = (exit_status % 256);
    }

    return (0);
}
