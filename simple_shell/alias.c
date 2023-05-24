#include "main.h"


#define MAX_ALIAS_LENGTH 50
#define MAX_COMMAND_LENGTH 100
#define MAX_ALIASES 50

typedef struct {
    char alias[MAX_ALIAS_LENGTH];
    char command[MAX_COMMAND_LENGTH];
} AliasEntry;

AliasEntry aliases[MAX_ALIASES];
int numAliases = 0;

void addAlias(char* alias, char* command) 
{
    // Check if the alias already exists
    int i;
    for (i = 0; i < numAliases; i++) {
        if (_strcmp(alias, aliases[i].alias) == 0) {
            _strncpy(aliases[i].command, command, MAX_COMMAND_LENGTH - 1);
            return;
        }
    }

    if (numAliases >= MAX_ALIASES) {
        printf("Maximum number of aliases reached.\n");
        return;
    }

    _strncpy(aliases[numAliases].alias, alias, MAX_ALIAS_LENGTH - 1);
    _strncpy(aliases[numAliases].command, command, MAX_COMMAND_LENGTH - 1);

    numAliases++;
}

void printAliases()
{
    if (numAliases == 0) {
        printf("No aliases defined.\n");
        return;
    }

    int i;
    for (i = 0; i < numAliases; i++) {
        printf("%s='%s'\n", aliases[i].alias, aliases[i].command);
    }
}

void printAlias(char* alias)
{
    int i;
    for (i = 0; i < numAliases; i++) {
        if (_strcmp(alias, aliases[i].alias) == 0) {
            printf("%s='%s'\n", aliases[i].alias, aliases[i].command);
            return;
        }
    }

    printf("Alias '%s' not found.\n", alias);
}

void removeAlias(char* alias)
{
    int i;
    for (i = 0; i < numAliases; i++) {
        if (_strcmp(alias, aliases[i].alias) == 0) {
            for (; i < numAliases - 1; i++) {
                _strncpy(aliases[i].alias, aliases[i + 1].alias, MAX_ALIAS_LENGTH - 1);
                _strncpy(aliases[i].command, aliases[i + 1].command, MAX_COMMAND_LENGTH - 1);
            }

            numAliases--;
            printf("Alias '%s' removed.\n", alias);
            return;
        }
    }

    printf("Alias '%s' not found.\n", alias);
}

int parseAliasCommand(char* input)
{
    char* token = _strtok(input, " \t");

    if (token == NULL) {
        printAliases();
        return 0;
    }

    if (_strcmp(token, "alias") == 0) {
        token = _strtok(NULL, " \t");
        if (token == NULL) {
            printAliases();
            return 0;
        }

        char* equal = _strchr(token, '=');
        if (equal != NULL) {
            *equal = '\0';
            char* alias = token;
            char* command = equal + 1;

            if (_strlen(alias) == 0 || strlen(command) == 0) {
                printf("Invalid syntax. Usage: alias [name[='value'] ...]\n");
                return 0;
            }

            addAlias(alias, command);
        } else {
            printAlias(token);
        }
    } else if (_strcmp(token, "unalias") == 0) {
        token = strtok(NULL, " \t");
        if (token == NULL) {
            printf("Invalid syntax. Usage: unalias <alias_name>\n");
            return 0;
        }

        removeAlias(token);
    } else {
        printf("Invalid command. Usage: alias [name[='value'] ...]\n");
        return 0;
    }

    return 0;
}
