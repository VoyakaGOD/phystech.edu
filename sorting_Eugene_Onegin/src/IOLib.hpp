#ifndef IOLIB_HEADER
#define IOLIB_HEADER

#include <stdlib.h>
#include <stdio.h>

/// @brief read all bytes from the file
/// @param[in] fileName name of the file, from whichwe read
/// @param[out] length, size of file in bytes, can be NULL
/// @return null-terminated string or NULL if error has appeared
char *ReadFile(const char *fileName, size_t *length);

/// @brief separate text to several strings by line ends
/// @param text the text, we wanna separate, each '\n' change to '\0'
/// @param[out] linesCount the number of lines in the text
/// @return array of pointers to each line or NULL if text is NULL
char **SeparateLines(char *text, long *linesCount);

/// @brief cancels changes in the text after using SeparateLines
/// @param text the text, in which each not last '\0' change to '\n'
/// @param[out] linesCount the number of lines in the text
/// @return if all is OK returns 1 or 0 if text is NULL
char RestoreLineEndings(char *text, long linesCount);

/// @brief Write one byte lines to file
/// @param[in] file file, in which we write
/// @param[in] lines array of null-terminated strings
/// @param[in] linesCount number of elements in the array
/// @return 1 if error has appeared, otherwise 0
char WriteLines(FILE *file, const char **lines, long linesCount);

#endif //IOLIB_HEADER