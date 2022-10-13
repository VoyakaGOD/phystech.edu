#ifndef CPU_COMMANDS_HEADER
#define CPU_COMMANDS_HEADER

#include "cpu_types.hpp"

const char *cpu_cmd_skip(context_t *cpu);

const char *cpu_cmd_push(context_t *cpu);

const char *cpu_cmd_add(context_t *cpu);

const char *cpu_cmd_sub(context_t *cpu);

const char *cpu_cmd_mul(context_t *cpu);

const char *cpu_cmd_in(context_t *cpu);

const char *cpu_cmd_out(context_t *cpu);

const char *cpu_cmd_dup(context_t *cpu);

const char *cpu_cmd_halt(context_t *cpu);

#endif //CPU_COMMANDS_HEADER