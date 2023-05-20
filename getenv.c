#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name) {
    if (name == NULL || *name == '\0' || strchr(name, '=') != NULL) {
        return NULL;  // Invalid environment variable name
    }

    int nameLength = strlen(name);

    for (int i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], name, nameLength) == 0 && environ[i][nameLength] == '=') {
            return &environ[i][nameLength + 1];  // Return the value of the environment variable
        }
    }

    return NULL;  // Environment variable not found
}

void printPathDirectories() {
    char *path = _getenv("PATH");

    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return;
    }

    char *copy = strdup(path);  // Create a copy of the PATH string

    if (copy == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    if (path != NULL) {
        printf("PATH: %s\n", path);
    } else {
        printf("PATH not found\n");
    }
    char *token = strtok(copy, ":");  // Split the PATH string using ":" delimiter

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }

    free(copy);  // Free the memory allocated for the copy
}
int main(void)
{
    printPathDirectories();
    return 0;
}

