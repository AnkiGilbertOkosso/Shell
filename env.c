#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *env[]) {
    printf("Address of env (main parameter): %p\n", (void *)env);
    printf("Address of environ (global variable): %p\n", (void *)environ);
    
    return 0;
}

