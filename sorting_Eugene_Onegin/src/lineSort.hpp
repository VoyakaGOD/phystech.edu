#ifndef LINE_SORT_HEADER
#define LINE_SORT_HEADER

#include <stdlib.h>
#include <assert.h>

/// @brief sorts array of wstrings taking in account only letters
/// @param[in] lines array of null-terminated wstrings
/// @param[in] count number of elements in the array
void SortLines(const wchar_t **lines, size_t count);

#endif //LINE_SORT_HEADER