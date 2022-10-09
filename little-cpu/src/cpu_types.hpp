#ifndef CPU_TYPES_HEADER
#define  CPU_TYPES_HEADER

#include "stack/stack.hpp"

typedef unsigned char byte;

typedef struct
{
    const byte *data;
    size_t size;
} code_t;

typedef struct
{
    code_t code;
    stack_t stack;
    long long RIP;
} context_t;

typedef (const char *) (*command_t) (context_t *cpu);

byte grab_byte(context_t *cpu);

long long grab_value(context_t *cpu);

void init_cpu(context_t *cpu, const char *source);

#endif // CPU_TYPES_HEADER