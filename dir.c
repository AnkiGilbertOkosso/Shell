#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

typedef struct Node {
    char *directory;
    struct Node *next;
} Node;

Node *buildPathLinkedList() {
    char *path = getenv("PATH");

    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return NULL;
    }

    Node *head = NULL;
    Node *prev = NULL;

    char *copy = strdup(path);  // Create a copy of the PATH string

    if (copy == NULL) {
        printf("Memory allocation error.\n");
        return NULL;
    }

    char *token = strtok(copy, ":");  // Split the PATH string using ":" delimiter

    while (token != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Memory allocation error.\n");
            return NULL;
        }

        newNode->directory = strdup(token);  // Create a copy of the directory string

        if (newNode->directory == NULL) {
            printf("Memory allocation error.\n");
            return NULL;
        }

        newNode->next = NULL;

        if (prev == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
        token = strtok(NULL, ":");
    }

    free(copy);  // Free the memory allocated for the copy

    return head;
}

void freePathLinkedList(Node *head) {
    while (head != NULL) {
        Node *current = head;
        head = head->next;
        free(current->directory);
        free(current);
    }
}

int main() {
    Node *pathList = buildPathLinkedList();

    if (pathList == NULL) {
        printf("Failed to build the linked list.\n");
        return 1;
    }

    Node *current = pathList;

    while (current != NULL) {
        printf("%s\n", current->directory);
        current = current->next;
    }

    freePathLinkedList(pathList);

    return 0;
}

