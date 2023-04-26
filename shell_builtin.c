#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	if (info->argv[1])
	{
		int exit_code = _erratoi(info->argv[1]);

		if (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_code;
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
    char *current_dir, *dir, buffer[1024];
    int chdir_ret;

    current_dir = getcwd(buffer, 1024);
    if (!current_dir)
        _puts("getcwd() error\n");

    if (!info->argv[1])
    {
        dir = _getenv(info, "HOME=");
        if (!dir)
        {
            dir = _getenv(info, "PWD=");
            chdir_ret = chdir(dir ? dir : "/");
        }
        else
        {
            chdir_ret = chdir(dir);
        }
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(current_dir);
            _putchar('\n');
            return (1);
        }

        _puts(_getenv(info, "OLDPWD="));
        _putchar('\n');
        chdir_ret = chdir((_getenv(info, "OLDPWD=")) ? _getenv(info, "OLDPWD=") : "/");
    }
    else
    {
        chdir_ret = chdir(info->argv[1]);
    }

    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }

    return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
    int i;
    char *builtin_commands[] = {"cd", "exit", "help", "env", "setenv", "unsetenv"};

    if (!info->argv[1])
    {
        _puts("Type `help name' to find out more about the function `name'.\n\n");
        _puts("List of built-in commands:\n");

        for (i = 0; i < 6; i++)
            _puts(builtin_commands[i]), _putchar('\n');

        _putchar('\n');
        _puts("For more information on command usage, type `man command-name'\n");
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            if (_strcmp(info->argv[1], builtin_commands[i]) == 0)
            {
                /* TODO: Add descriptions for each command */
                _puts("TODO: Add description for this command\n");
                return (0);
            }
        }
        print_error(info, "command not found: ");
        _eputs(info->argv[1]), _eputchar('\n');
    }
    return (0);
}
