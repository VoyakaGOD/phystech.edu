#include "cpu_types.hpp"

byte grab_byte(context_t *ctx)
{
    return ctx->code.data[ctx->regs.RIP++];
}

long long grab_value(context_t *ctx)
{
    long long *ptr = (long long *)(ctx->code.data + ctx->regs.RIP);
    ctx->regs.RIP += sizeof(long long);
    return *ptr;
}

long long load_reg(context_t *ctx, byte index)
{
    long long *reg = &ctx->regs.RAX;
    reg += index;
    return *reg;
}

void set_reg(context_t *ctx, byte index, long long value)
{
    long long *reg = &ctx->regs.RAX;
    reg += index;
    *reg = value;
}

context_t create_context(FILE *file, size_t stack_capacity, size_t ram_size)
{
    long long *ram = (long long *)calloc(ram_size, sizeof(long long));
    context_t context = {ram};
    
    STACK_INIT(context.stack, stack_capacity);

    fseek(file, 0, SEEK_END);
    context.code.size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    byte *data = (byte *)calloc(context.code.size, sizeof(char));
    fread(data, sizeof(char), context.code.size, file);
    context.code.data = data;
    
    return context;
}