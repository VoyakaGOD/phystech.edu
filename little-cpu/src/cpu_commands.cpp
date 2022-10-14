#include "cpu_commands.hpp"

#define CONDITIONAL_JMP_CMD(name, v) const char *name(byte prefix, context_t *ctx)\
{\
    long long right = stack_pop(&ctx->stack);\
    long long left = stack_pop(&ctx->stack);\
    long long arg = grab_value(ctx);\
    if(left v right)\
        ctx->regs.RIP = arg;\
    return NULL;\
}

#define MATH_CMD(name, op) const char *name(byte prefix, context_t *ctx)\
{\
    long long right = stack_pop(&ctx->stack);\
    long long left = stack_pop(&ctx->stack);\
    stack_push(&ctx->stack, left op right);\
    return NULL;\
}

static const byte IMMEDIATE_PREFIX = 0x00;
static const byte RAM_PREFIX = 0x40;
static const byte REG_PREFIX = 0x80;
static const byte NO_ARGS_PREFIX = 0xC0;

const char *cpu_cmd_skip(byte prefix, context_t *ctx)
{
    return NULL;
}

const char *cpu_cmd_push(byte prefix, context_t *ctx)
{
    if(prefix == IMMEDIATE_PREFIX)
        stack_push(&ctx->stack, grab_value(ctx));
    else if(prefix == REG_PREFIX)
        stack_push(&ctx->stack, load_reg(ctx, grab_byte(ctx)));
    else if(prefix == RAM_PREFIX)
        stack_push(&ctx->stack, ctx->RAM[grab_value(ctx)]);
    else
        return "Incorrect command prefix";

    return NULL;
}

const char *cpu_cmd_pop(byte prefix, context_t *ctx)
{
    if(prefix == REG_PREFIX)
        set_reg(ctx, grab_byte(ctx), stack_pop(&ctx->stack));
    else if(prefix == RAM_PREFIX)
        ctx->RAM[grab_value(ctx)] = stack_pop(&ctx->stack);
    else
        return "Incorrect command prefix";
    
    return NULL;
}

MATH_CMD(cpu_cmd_add, +)

MATH_CMD(cpu_cmd_sub, -)

MATH_CMD(cpu_cmd_mul, *)

MATH_CMD(cpu_cmd_div, /)

MATH_CMD(cpu_cmd_mod, %)

const char *cpu_cmd_in(byte prefix, context_t *ctx)
{
    long long value;
    scanf("%lld", &value);

    stack_push(&ctx->stack, value);

    return NULL;
}

const char *cpu_cmd_out(byte prefix, context_t *ctx)
{
    printf("out: %lld\n", stack_pop(&ctx->stack));

    return NULL;
}

const char *cpu_cmd_dup(byte prefix, context_t *ctx)
{
    stack_push(&ctx->stack, stack_peek(&ctx->stack));

    return NULL;
}

const char *cpu_cmd_jmp(byte prefix, context_t *ctx)
{
    ctx->regs.RIP = grab_value(ctx);

    return NULL;
}

CONDITIONAL_JMP_CMD(cpu_cmd_je, ==)

CONDITIONAL_JMP_CMD(cpu_cmd_jne, ==)

CONDITIONAL_JMP_CMD(cpu_cmd_jg, >)

CONDITIONAL_JMP_CMD(cpu_cmd_jge, >=)

CONDITIONAL_JMP_CMD(cpu_cmd_jl, <)

CONDITIONAL_JMP_CMD(cpu_cmd_jle, <=)

const char *cpu_cmd_halt(byte prefix, context_t *ctx)
{
    return "Execution of the program was successfuly ended!";
}