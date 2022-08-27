#ifndef MY_STR_LIB_HEADER
#define MY_STR_LIB_HEADER

#include <stdlib.h>
#include <stdio.h>

//int puts(const char *string);

char *strchr(char *string, int symbol);

size_t strlen(const char * string);

char *strcpy(char *dest, const char *src);

char *strncpy(char *dest, const char *src, size_t num);

char *strcat(char *dest, const char *src);

char *strncat(char *dest, const char *src, size_t num);

//char *fgets(char *string, int num, FILE *filestream);

char *strdup(const char *src);

/*
getline*/

#endif //MY_STR_LIB_HEADER