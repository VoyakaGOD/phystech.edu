#ifndef IOLIB_HEADER
#define IOLIB_HEADER

#include <stdlib.h>
#include <stdio.h>

/// @brief read all bytes from the file
/// @param[in] fileName name of the file, from whichwe read
/// @return null-terminated string or NULL if error has appeared
char *ReadFile(const char *fileName);

/// @brief separate text to several strings by line ends
/// @param text the text, we wanna separate, each '\n' change to '\0'
/// @param[out] linesCount the number of lines in the text
/// @return array of pointers to each line or NULL if text is NULL
char **SeparateLines(char *text, long *linesCount);

/// @brief Write one byte lines to file
/// @param[in] fileName name of the file, in which we write
/// @param[in] lines array of null-terminated strings
/// @param[in] linesCount number of elements in the array
/// @return 1 if error has appeared, otherwise 0
char WriteLines(const char *fileName, const char **lines, long linesCount);

#endif //IOLIB_HEADER