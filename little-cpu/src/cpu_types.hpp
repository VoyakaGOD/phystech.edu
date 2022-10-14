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
    long long RAX;
    long long RBX;
    long long RCX;
    long long RDX;
    long long RIP;
}regs_t;

typedef struct
{
    long long * const RAM;
    code_t code;
    stack_t stack;
    regs_t regs;
} context_t;

typedef const char * (*command_t) (byte prefix, context_t *ctx);

byte grab_byte(context_t *ctx);

long long grab_value(context_t *ctx);

long long load_reg(context_t *ctx, byte index);

void set_reg(context_t *ctx, byte index, long long value);

context_t create_context(FILE *file, size_t stack_capacity, size_t ram_size);

#endif // CPU_TYPES_HEADER