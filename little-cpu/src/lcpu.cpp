#include "cpu_commands.hpp"
#include "cpu_types.hpp"

void lcpu(context_t *cpu, command_t *commands, const byte commands_count)
{
    while(true)
    {
        //printf("RIP: %lld, stack: %ld\n", cpu->RIP, cpu->stack.size);
        if(cpu->regs.RIP >= cpu->code.size)
        {
            printf("Unexpected end of code...\n");
            return;
        }

        byte id = grab_byte(cpu);
        byte prefix = id & 0xC0;
        id -= prefix;
        if(id >= commands_count)
        {
            printf("Unexpected command[%x] at [%lld]!", id, cpu->regs.RIP);
            return;
        }

        const char *result = commands[id](prefix, cpu);
        if(result != NULL)
        {
            printf("At command[%x] at IP[%lld]:", id, cpu->regs.RIP);
            printf("%s\n", result);
            return;
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Correct format: lcpu [file]");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL)
    {
        printf("Incorrect source file!");
        return -1;
    }

    context_t context = create_context(file, 256, 1024);
    fclose(file);

    command_t commands[] = {
        cpu_cmd_skip,      //0
        cpu_cmd_push,      //1
        cpu_cmd_add,       //2
        cpu_cmd_sub,       //3
        cpu_cmd_mul,       //4
        cpu_cmd_in,        //5
        cpu_cmd_out,       //6
        cpu_cmd_dup,       //7
        cpu_cmd_halt,      //8
        cpu_cmd_pop        //9
    };

    lcpu(&context, commands, sizeof(commands) / sizeof(command_t));
}
