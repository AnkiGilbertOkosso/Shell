#include "main.h"
/* function to create new alias */
alias_t *create_alias(const char *name, const char *value)
{
    alias_t *new_node = (alias_t *)malloc(sizeof(alias_t));

    new_node->name = _strdup(name);
    new_node->value = _strdup(value);
    new_node->next = NULL;
    return new_node;
}


/* Function to create a new alias node */
void free_alias_list(runtime_data *data)
{
    alias_t *current = alias_list;
    alias_t *next;

    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
    alias_list = NULL;
}


/* Function to set an alias */
void set_alias(const char *name, const char *value) 
{
    alias_t *current = alias_list;
    alias_t *new_node;

    while (current != NULL) {
        if (_strcmp(current->name, name) == 0) {
            free(current->value);
            current->value = _strdup(value);
            return;
        }
        current = current->next;
    }

    new_node = create_alias(name, value);
    new_node->next = alias_list;
    alias_list = new_node;
}

/* Function to unset an alias */
void unset_alias(const char *name) 
{
    alias_t *current = alias_list;
    alias_t *prev = NULL;

    while (current != NULL) {
        if (_strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                alias_list = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->value);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
/*  Function to print all aliases */
void print_alias()
{
    alias_t *current = alias_list;
    while (current != NULL) {
        printf("%s='%s'\n", current->name, current->value);
        current = current->next;
    }
}