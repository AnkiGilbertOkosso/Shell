#include "shell.h"

void prompt(char **av, char **env)
{
    char *str = NULL;
    int i, status;
    ssize_t line, n = 0;
    pid_t child_pid;
    char *argv[] = {NULL, NULL};

    while (1)
    {
        printf("$ ");
        line = getline(&str, &n, stdin);
        if (line == -1)
        {
            free(str);
            exit(EXIT_FAILURE);
        }
        i = 0;
        while (str[i])
        {
            if (str[i] == '\n')
                str[i] = '\0';
        }
        argv[0] = str;
        child_pid = fork();
        if (child_pid == -1)
        {
            free(str);
            exit(EXIT_FAILURE);
        }
        if (child_pid == 0)
        {
            if (execve(argv[0], argv, env) == -1)
                printf("%s: NO such file or directory\n", av[0]);
        }
        else
            wait(&status);
    }
}