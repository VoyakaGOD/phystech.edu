#include "cpu_types.hpp"

byte grab_byte(context_t *cpu)
{
    return cpu->code.data[cpu->RIP++];
}

long long grab_value(context_t *cpu)
{
    long long *ptr = (long long *)(cpu->code.data + cpu->RIP);
    code->index += sizeof(long long);
    return *ptr;
}

void init_cpu(context_t *cpu, const char *source)
{

}