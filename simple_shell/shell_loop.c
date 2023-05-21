#include "main.h"
/**
 * shell_loop - Loop of the shell
 * @data: data relevants (arguments, input, tokens)
 *
 * Return: no return.
 */
void shell_loop(runtime_data *data)
{
    int loop = 1, eof;
    char *input;

    while (loop == 1)
    {
        printf("#cisfun$ ");
        input = read_line(&eof);
        if (eof != -1)
        {
            if (input == NULL)
                continue;
            if (syntax_error(data, input) == 1)
            {
                data->status = 2;
                free(input);
                continue;
            }
            input = replace_var(input, data);
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
