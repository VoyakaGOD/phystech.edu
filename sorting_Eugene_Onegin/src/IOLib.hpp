#ifndef IOLIB_HEADER
#define IOLIB_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

wchar_t *ReadLine(FILE *file);

wchar_t **ReadAllLines(const char *fileName, size_t *linesCount);

void WriteAllLines(const char *fileName, const wchar_t **lines, size_t linesCount);

#endif //IOLIB_HEADER