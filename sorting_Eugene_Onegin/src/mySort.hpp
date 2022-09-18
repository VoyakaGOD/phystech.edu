#ifndef MY_SORT_HEADER
#define MY_SORT_HEADER

#include <stdlib.h>
#include <assert.h>

typedef int (*compare_func_t) (const void *, const void *);

/// @brief sorts array of any elements
/// @param[in] array array we wanna sort
/// @param[in] count number of elements in the array
/// @param[in] size size in bytes of each element
/// @param[in] compare function which compare two elements
void MySort(void *array, size_t count, size_t size, compare_func_t compare);

#endif //MY_SORT_HEADER