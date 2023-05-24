#include "main.h"

char* _strncpy(char* destination, const char* source, size_t num)
{
    char* dest = destination;
    const char* src = source;
    size_t i;

    for (i = 0; i < num && *src != '\0'; i++) {
        *dest++ = *src++;
    }

    for (; i < num; i++) {
        *dest++ = '\0';
    }

    return destination;
}

size_t _strcspn(const char* str, const char* charset)
{
    size_t i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; charset[j] != '\0'; j++) {
            if (str[i] == charset[j]) {
                return i;
            }
        }
    }
    return i;
}

int _strncmp(const char* str1, const char* str2, size_t n)
{
    size_t i;

    for (i = 0; i < n; i++) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];

        if (str1[i] == '\0' || str2[i] == '\0')
            break;
    }

    return 0;
}