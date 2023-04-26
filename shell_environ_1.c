#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}


/**
 * _setenv - Initialize a new environment striable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @str: the string env str property
 * @value: the string env str value
 *  Return: Always 0
 */
int _setenv(info_t *info, char *str, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *c;

	if (!str || !value)
		return (0);

	buffer = malloc(_strlen(str) + _strlen(value) + 2);
	if (!buffer)
		return (1);
	_strcpy(buffer, str);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		c = starts_with(node->str, str);
		if (c && *c == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, 0);
	free(buffer);
	info->env_changed = 1;
	return (0);
}

/**
 * _unsetenv - Remove an environment striable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @str: the string env str property
 */
int _unsetenv(info_t *info, char *str)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !str)
		return (0);

	while (node)
	{
		p = starts_with(node->str, str);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}