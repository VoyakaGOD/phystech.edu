#ifndef LINE_SORT_HEADER
#define LINE_SORT_HEADER

#include "mySort.hpp"

/// @brief sorts array of strings taking in account only letters
/// @param[in] lines array of null-terminated strings
/// @param[in] count number of elements in the array
/// @return 1 if lines is NULL, otherwise 0
char SortLines(const char **lines, size_t count);

/// @brief sorts array of strings from end taking in account only letters
/// @param[in] lines array of null-terminated strings
/// @param[in] count number of elements in the array
/// @return 1 if lines is NULL, otherwise 0
char SortFlippedLines(const char **lines, size_t count);

#endif //LINE_SORT_HEADER