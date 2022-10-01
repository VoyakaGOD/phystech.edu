#ifndef PROG_LOG_HEADER
#define PROG_LOG_HEADER

#include <stdio.h>

extern FILE *log_file;

int set_log_file(const char *path);

void close_log_file();

#endif //PROG_LOG_HEADER