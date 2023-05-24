#include "main.h"

/**
 * commet_out - deletes comments from input
 *
 * @str: input string
 * Return: input without the comments
 */
char *commet_out(char *str)
{
	int a, b;

	b = 0;
	for (a = 0; str[a]; a++)
	{
		if (str[a] == '#')
		{
			if (a == 0)
			{
				free(str);
				return (NULL);
			}

			if (str[a - 1] == ' ' || str[a - 1] == '\t' || str[a - 1] == ';')
				b = a;
		}
	}

	if (b != 0)
	{
		str = _realloc(str, a, b + 1);
		str[b] = '\0';
	}

	return (str);
}
/**
 * shell_loop - Loop of the shell
 * @data: data relevants (arguments, input, tokens)
 *
 * Return: no return.
 */
void shell_loop(runtime_data *data)
{
    int loop, eof;
    char *input;

    loop = 1;
    while (loop == 1)
    {
        write(STDIN_FILENO, "$ ", 2);
        input = read_line(&eof);
        if (eof != -1)
        {
            input = commet_out(input);
            if (input == NULL)
                continue;
            if (syntax_error(data, input) == 1)
            {
                data->status = 2;
                free(input);
                continue;
            }
            input = replace_var(input, data);
            if (strncmp(input, "alias", 5) == 0) {
                parseAliasCommand(input);
                free(input);
                continue;
            }
            loop = split_cmd(data, input);
            data->lineCounter += 1;
            free(input);
        }
        else
        {
            loop = 0;
            free(input);
        }
    }
}
/**
 * read_line - reads the inputs of string.
 *
 * @eof: return value of the getline function
 * Return: inputs string
 */
char *read_line(int *eof)
{
	char *inputs = NULL;
	size_t buffersize = 0;

	*eof = getline(&inputs, &buffersize, stdin);

	return (inputs);
}
