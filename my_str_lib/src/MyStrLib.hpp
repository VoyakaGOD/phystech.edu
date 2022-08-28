#ifndef MY_STR_LIB_HEADER
#define MY_STR_LIB_HEADER

#include <stdlib.h>
#include <stdio.h>

/// @brief identify length of the string without '\0'
/// @param[in] string the string which length we wanna know
/// @return length of the string 
size_t strlen(const char *string);

/// @brief copy each char form src to dest including '\0'
/// @param[out] dest destination string
/// @param[in] src source string
/// @return destination string pointer
char *strcpy(char *dest, const char *src);

/// @brief copy N chars form src to dest, always add '\0' to end
/// @param[out] dest destination string
/// @param[in] src source string
/// @param[in] num count of chars to copy
/// @return destination string pointer
char *strncpy(char *dest, const char *src, size_t num);

/// @brief find symbol in string
/// @param[in] string the string
/// @param[in] symbol the symbol
/// @return pointer to finded symbol if it was founded otherwise NULL
char *strchr(char *string, int symbol);

/// @brief compare two strings
/// @param[in] string1 the first string
/// @param[in] string2 the second string
/// @return difference between first different chars or zero if strins is equal
int strcmp(const char *string1, const char *string2);

/// @brief copy each char form src to end of dest including '\0'
/// @param[out] dest destination string
/// @param[in] src source string
/// @return destination string pointer
char *strcat(char *dest, const char *src);

/// @brief copy N chars form src to end of dest, always add '\0' to end
/// @param[out] dest destination string
/// @param[in] src source string
/// @param[in] num count of chars to copy
/// @return destination string pointer
char *strncat(char *dest, const char *src, size_t num);

/// @brief create full copy of string
/// @param[in] src original string
/// @return pointer to copy
char *strdup(const char *src);

/// @brief print string to stdin
/// @param[in] string the string
int mputs(const char *string);

/// @brief read less than limit chars from file while not found end char and save them to string
/// @param[in] string the string
/// @param[in] end end char
/// @param[in] limit max count of chars
/// @param[in] file from which we wanna read
/// @return pointer to string or NULL if read no char.
char *getline(char *string, char end, int limit, FILE *file);

/// @brief read less than limit chars from file while not found '\n' char and save them to string
/// @param[in] string the string
/// @param[in] limit max count of chars
/// @param[in] file from which we wanna read
/// @return pointer to string or NULL if read no char.
char *mfgets(char *string, int num, FILE *file);

#endif //MY_STR_LIB_HEADER