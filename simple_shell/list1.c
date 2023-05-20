#include "main.h"

/**
 * add_var_node - adds the variable at the end
 * of the var_list list.
 * @head: head of a linked list.
 * @len_var: length of a variable.
 * @val: value of a variable.
 * @len_val: length of a value.
 * Return: address of a head.
 */
var_list *add_var_node(var_list **head, int len_var, char *val, int len_val)
{
	var_list *new, *temp;

	new = malloc(sizeof(var_list));
	if (new == NULL)
		return (NULL);

	new->var_len = len_var;
	new->value = val;
	new->len_value = len_val;

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
 * free_var_list - frees the var_list list
 * @head: head of a linked list.
 * Return: no return.
 */
void free_var_list(var_list **head)
{
	var_list *temp;
	var_list *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
