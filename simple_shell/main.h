#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <signal.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

typedef struct shell_data
{
    char **arguments;
    char *input;
    char **tokens;
    int status;
    int lineCounter;
    char **_env;
    char *pid;
}runtime_data;

/**
 * struct variable - the single linked list
 * @var_len: the length of the variable
 * @value: the value of the variable
 * @len_value: the length of the value
 * @next: represent next node
 * Description: the single linked list to store variables
 */
typedef struct variable
{
	int var_len;
	char *value;
	int len_value;
	struct variable *next;
} var_list;


/**
 * struct single_list - single linked list
 * @sep: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct single_list
{
	char sep;
	struct single_list *next;
} separator_list;



/**
 * struct command_line - single linked list
 * @line: represent command line
 * @next: represent next node
 * Description: this is single linked list to store command lines
 */
typedef struct command_line
{
	char *line;
	struct command_line *next;
} cmd_list;

/**
 * struct builtin - Builtin struct for the command args.
 * @name: The name of the command builtin i.e for cd, exit, env
 * @f: data type for pointer function.
 */
typedef struct builtin
{
	char *name;
	int (*f)(runtime_data *data);
} builtin_cmd;



/*shell_loop.c */
void shell_loop(runtime_data *data);
char *read_line(int *eof);

/* signal.c */ 
void get_sigint(int signal);

/* memory.c */ 
void free_data(runtime_data *data);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);


/* strings1.c */ 
char *_strdup(const char *s);
int _strlen(const char *s);
void *_memcpy(void *dest, const void *src, size_t n);
char *_strcat(char *newstr, const char *str);
char *_strcpy(char *newstr, char *str);

/* strings2.c */ 
char *_strchr(char *str, char c);
int _strspn(char *str, char *s);
int _strcmp(char *str1, char *str2);
int _isdigit(const char *str);
void rev_str(char *str);

/* strings3.c */ 
int _atoi(char *str);
char *int_to_string(int num) ;
int get_len(int num);
char *_strtok(char str[], const char *delimiter);
int _charscmp(char str[], const char *delimiter);

/* syntax_error.c */
int char_dup(char *str, int n);
int find_syntax_error(char *str, int i, char last_char);
int first_char(char *str, int *n);
int syntax_error(runtime_data *data, char *str);
void print_syntax_error(runtime_data *data, char *str, int n, int bol);

/*  env_vars.c */
void search_env(var_list **list, char *str, runtime_data *data);
int search_vars(var_list **head, char *str, char *status, runtime_data *data);
char *replaced_string(var_list **head, char *str, char *new_str, int new_len);
char *replace_var(char *str, runtime_data *data);

/* list1.c */
var_list *add_var_node(var_list **head, int len_var, char *val, int len_val);
void free_var_list(var_list **head);

/* tokenizer.c */
char *swap_char(char *str, int n);
void add_node(separator_list **head_sep, cmd_list **head_line, char *str);
void _next(separator_list **list_sep, cmd_list **list_line, runtime_data *data);
char **tokenize(char *str);
int split_cmd(runtime_data *data, char *str);


/* list2.c */ 
separator_list *add_sep(separator_list **head, char separator);
cmd_list *add_line(cmd_list **head, char *line);
void free_sep(separator_list **head);
void free_line(cmd_list **head);

/* execute.c */ 
int _execute(runtime_data *data);
int (*get_builtin(char *command))(runtime_data *);


/* exec_cmd.c */ 
int is_currentdir(char *path, int *n);
char *_which(char *command, char **_environ);
int is_exec(runtime_data *data);
int check_error(char *directory, runtime_data *data);
int _exec(runtime_data *data);

/* error1.c */ 
int get_error(runtime_data *data, int val_error);
char *exit_error(runtime_data *data);
char *command_not_found(runtime_data *data);
char *env_error(runtime_data *data);
char *error_path(runtime_data *data);

/* error2.c */ 
char *cd_error(runtime_data *data);
char *strcat_cd(runtime_data *data, char *msg, char *error_checker, char *str);


/* environ1.c */ 
int cmp_env_var(const char *env_name, const char *str);
char *_getenv(const char *str, char **_environ);
int _env(runtime_data *data);


#endif