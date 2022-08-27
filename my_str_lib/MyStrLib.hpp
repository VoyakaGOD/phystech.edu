#ifndef MY_STR_LIB_HEADER
#define MY_STR_LIB_HEADER

#include <stdlib.h>
#include <stdio.h>

int mputs(const char *string);

char *strchr(char *string, int symbol);

size_t strlen(const char * string);

char *strcpy(char *dest, const char *src);

char *strncpy(char *dest, const char *src, size_t num);

char *strcat(char *dest, const char *src);

char *strncat(char *dest, const char *src, size_t num);

char *getline(char *string, char end, int limit, FILE *file);

char *mfgets(char *string, int num, FILE *file);

char *strdup(const char *src);

#endif //MY_STR_LIB_HEADER