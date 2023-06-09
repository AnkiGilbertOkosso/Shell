#include "main.h"



void set_data(runtime_data *data, char **av)
{
    unsigned int x;
    
    data->arguments = av;
    data->input = NULL;
    data->tokens = NULL;
    data->status = 0;
    data->lineCounter = 1;
    for (x = 0; environ[x]; x++)
        ;
    data->_env = malloc(sizeof(char *) * (x + 1));

    for (x = 0; environ[x]; x++)
        data->_env[x] = _strdup(environ[x]);
    data->_env[x] = NULL;
    data->pid = int_to_string(getpid());
}


int main(int ac, char **av)
{
    runtime_data data;
    (void) ac;

    signal(SIGINT, get_sigint);
    set_data(&data, av);
    shell_loop(&data);
    free_data(&data);

    if (data.status < 0)
        return (255);
    return (data.status);
}

