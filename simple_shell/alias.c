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
    int i;

    if (numAliases == 0) {
        printf("No aliases defined.\n");
        return;
    }

    for (i = 0; i < numAliases; i++) {
        printf("%s='%s'\n", aliases[i].alias, aliases[i].command);
    }
}

void printAlias(char* alias)
{
    int i;
    for (i = 0; i < numAliases; i++) {
        if (_strncmp(alias, aliases[i].alias, MAX_ALIAS_LENGTH - 1) == 0) {
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
    char* equal = _strchr(token, '=');
    /*char* alias = token;
    char* command = equal + 1;*/


    if (token == NULL) {
        printAliases();
        return 0;
    }

    if (_strcmp(token, "alias") == 0) {
        token = _strtok(NULL, " \t");
        if (token == NULL) {
            printAliases();
            return 0;
        } else if (equal != NULL) {
            while (token != NULL) {
                addAlias(token, token + _strlen(token) + 1);
                token = _strtok(NULL, " \t");
            }
        } else {
            while (token != NULL) {
                printAlias(token);
                token = _strtok(NULL, " \t");
            }
        }
    } else if (_strcmp(token, "unalias") == 0) {
        token = _strtok(NULL, " \t");
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
