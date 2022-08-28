#ifndef IOLIB_HEADER
#define IOLIB_HEADER

#include <stdio.h>

char *ReadLine(FILE *file);

char **ReadAllLines(FILE *file);

void WriteLine(FILE *file, const char *line);

void WriteAllLines(FILE *file, const char **lines);

#endif //IOLIB_HEADER