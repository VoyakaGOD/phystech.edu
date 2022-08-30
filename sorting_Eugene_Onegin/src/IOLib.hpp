#ifndef IOLIB_HEADER
#define IOLIB_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

/// @brief Read UTF-8 line from file
/// @param[in] file file, from which we read
/// @return null-terminated wstring 
wchar_t *ReadLine(FILE *file);

/// @brief Read all UTF-8 lines from file
/// @param[in] fileName name of the file, from which we read
/// @param[out] linesCount number of read lines
/// @return array of null-terminated wstrings
wchar_t **ReadAllLines(const char *fileName, size_t *linesCount);

/// @brief Write UTF-8 lines to file
/// @param[in] fileName name of the file, in which we write
/// @param[in] lines array of null-terminated wstrings
/// @param[in] linesCount number of elements in the array
void WriteAllLines(const char *fileName, const wchar_t **lines, size_t linesCount);

#endif //IOLIB_HEADER