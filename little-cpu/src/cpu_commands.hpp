#ifndef CPU_COMMANDS_HEADER
#define CPU_COMMANDS_HEADER

#include "cpu_types.hpp"

const char *cpu_cmd_skip(byte prefix, context_t *cpu);

const char *cpu_cmd_push(byte prefix, context_t *cpu);

const char *cpu_cmd_pop(byte prefix, context_t *cpu);

const char *cpu_cmd_add(byte prefix, context_t *cpu);

const char *cpu_cmd_sub(byte prefix, context_t *cpu);

const char *cpu_cmd_mul(byte prefix, context_t *cpu);

const char *cpu_cmd_div(byte prefix, context_t *cpu);

const char *cpu_cmd_mod(byte prefix, context_t *cpu);

const char *cpu_cmd_in(byte prefix, context_t *cpu);

const char *cpu_cmd_out(byte prefix, context_t *cpu);

const char *cpu_cmd_dup(byte prefix, context_t *cpu);

const char *cpu_cmd_jmp(byte prefix, context_t *cpu);

const char *cpu_cmd_je(byte prefix, context_t *cpu);

const char *cpu_cmd_jne(byte prefix, context_t *cpu);

const char *cpu_cmd_jg(byte prefix, context_t *cpu);

const char *cpu_cmd_jge(byte prefix, context_t *cpu);

const char *cpu_cmd_jl(byte prefix, context_t *cpu);

const char *cpu_cmd_jle(byte prefix, context_t *cpu);

const char *cpu_cmd_halt(byte prefix, context_t *cpu);

#endif //CPU_COMMANDS_HEADER