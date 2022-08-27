#include "MyStrLib.hpp"

//////////////////

char *strchr(char *string, int symbol)
{
    for(size_t i = 0; string[i]; i++)
        if (string[i] == symbol)
            return string + i;
    return NULL;
}

size_t strlen(const char * string)
{
    size_t len = 0;
    while(string[len])
        len++;
    return len;
}

char *strcpy(char *dest, const char *src)
{
    size_t ptr = 0;
    do
    {
        dest[ptr] = src[ptr];
    }
    while(src[ptr++]);
    return dest;
}

char *strncpy(char *dest, const char *src, size_t num)
{
    size_t ptr = 0;
    do
    {
        dest[ptr] = src[ptr];
    }
    while(src[ptr++] && (--num));

    if (!num && !src[ptr - 1])
        dest[ptr] = '\0';

    return dest;
}

char *strcat(char *dest, const char *src)
{
    return strcpy(dest + strlen(dest), src);
}

char *strncat(char *dest, const char *src, size_t num)
{
    return strncpy(dest + strlen(dest), src, num);
}

//////////////////

char *strdup(const char *src)
{
    char *duplicate = (char*)malloc((strlen(src) + 1) * sizeof(char));
    return strcpy(duplicate, src);
}