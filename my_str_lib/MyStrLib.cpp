#include "MyStrLib.hpp"

int mputs(const char *string)
{
    for(size_t i = 0; string[i]; i++)
        putchar(string[i]);
    putchar('\n');
    return 1;
}

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
    size_t index = 0;
    do
    {
        dest[index] = src[index];
    }
    while(src[index++]);
    return dest;
}

char *strncpy(char *dest, const char *src, size_t num)
{
    if(num == 0)
        return dest;
    
    size_t index = 0;
    do
    {
        dest[index] = src[index];
    }
    while(src[index++] && (--num));

    if (!num && !src[index - 1])
        dest[index] = '\0';

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

char *getline(char *string, char end, int limit, FILE *file)
{
    if(limit == 0)
        return string;

    int symbol = 0;
    char *index = string;
    while((symbol = getc(file)) != EOF && (--limit) > 0)
    {
        *(index++) = symbol;
        if(symbol == end)
            break;
    }
    *index = '\0';
    return (symbol == EOF && index == string) ? NULL : string;
}

char *mfgets(char *string, int num, FILE *file)
{
    return getline(string, '\n', num, file);
}

char *strdup(const char *src)
{
    char *duplicate = (char*)malloc((strlen(src) + 1) * sizeof(char));
    return strcpy(duplicate, src);
}