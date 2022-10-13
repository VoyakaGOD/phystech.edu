#include "cpu_types.hpp"

byte grab_byte(context_t *cpu)
{
    return cpu->code.data[cpu->RIP++];
}

long long grab_value(context_t *cpu)
{
    long long *ptr = (long long *)(cpu->code.data + cpu->RIP);
    cpu->RIP += sizeof(long long);
    return *ptr;
}

context_t create_context(FILE *file)
{
    context_t context = {};
    STACK_INIT(context.stack, 256);

    fseek(file, 0, SEEK_END);
    context.code.size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    byte *data = (byte *)calloc(context.code.size, sizeof(char));
    fread(data, sizeof(char), context.code.size, file);
    context.code.data = data;
    
    return context;
}