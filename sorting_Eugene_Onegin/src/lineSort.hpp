#ifndef LINE_SORT_HEADER
#define LINE_SORT_HEADER

#include <stddef.h>

//static cmp func for qsort
void CompareLines(const char *first, const char *second);

void SortLines(const char **lines);

#endif //LINE_SORT_HEADER