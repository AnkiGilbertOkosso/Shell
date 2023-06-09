#include "main.h"

/**
 * add_sep - adds the separator found at end
 * of a separator_list.
 * @head: head of a linked list.
 * @separator: separator found (; | &).
 * Return: address of a head.
 */
separator_list *add_sep(separator_list **head, char separator)
{
	separator_list *new, *temp;

	new = malloc(sizeof(separator_list));
	if (new == NULL)
		return (NULL);

	new->sep = separator;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * add_line - adds the command line at a end
 * of a cmd_list.
 * @head: head of a linked list.
 * @line: command line.
 * Return: address of a head.
 */
cmd_list *add_line(cmd_list **head, char *line)
{
	cmd_list *new, *temp;

	new = malloc(sizeof(cmd_list));
	if (new == NULL)
		return (NULL);
	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * free_sep - frees the separator_list
 * @head: head of a linked list.
 * Return: no return.
 */
void free_sep(separator_list **head)
{
	separator_list *temp;
	separator_list *node;

	if (head != NULL)
	{
		node = *head;
		while ((temp = node) != NULL)
		{
			node = node->next;
			free(temp);
		}
		*head = NULL;
	}
}


/**
 * free_line - frees the cmd_list
 * @head: head of a linked list.
 * Return: no return.
 */
void free_line(cmd_list **head)
{
	cmd_list *temp;
	cmd_list *node;

	if (head != NULL)
	{
		node = *head;
		while ((temp = node) != NULL)
		{
			node = node->next;
			free(temp);
		}
		*head = NULL;
	}
}
