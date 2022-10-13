#include "cpu_commands.hpp"

const char *cpu_cmd_skip(context_t *cpu)
{
    return NULL;
}

const char *cpu_cmd_push(context_t *cpu)
{
    stack_push(&cpu->stack, grab_value(cpu));

    return NULL;
}

const char *cpu_cmd_add(context_t *cpu)
{
    if(cpu->stack.size < 2)
        return "Not enough items to add!";

    long long left = stack_pop(&cpu->stack);
    long long right = stack_pop(&cpu->stack);

    stack_push(&cpu->stack, left + right);

    return NULL;
}

const char *cpu_cmd_sub(context_t *cpu)
{
    if(cpu->stack.size < 2)
        return "Not enough items to sub!";

    long long left = stack_pop(&cpu->stack);
    long long right = stack_pop(&cpu->stack);

    stack_push(&cpu->stack, left - right);

    return NULL;
}

const char *cpu_cmd_mul(context_t *cpu)
{
    if(cpu->stack.size < 2)
        return "Not enough items to mul!";

    long long left = stack_pop(&cpu->stack);
    long long right = stack_pop(&cpu->stack);

    stack_push(&cpu->stack, left * right);

    return NULL;
}

const char *cpu_cmd_in(context_t *cpu)
{
    long long value;
    scanf("%lld", &value);

    stack_push(&cpu->stack, value);

    return NULL;
}

const char *cpu_cmd_out(context_t *cpu)
{
    printf("out: %lld", stack_pop(&cpu->stack));

    return NULL;
}

const char *cpu_cmd_dup(context_t *cpu)
{
    stack_push(&cpu->stack, stack_peek(&cpu->stack));

    return NULL;
}

const char *cpu_cmd_halt(context_t *cpu)
{
    return "Execution of the program was successfuly ended!";
}