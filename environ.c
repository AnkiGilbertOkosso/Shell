#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main() {
    // Accessing environment variables
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }
    
    return 0;
}

