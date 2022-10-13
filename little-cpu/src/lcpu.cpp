#include "cpu_commands.hpp"
#include "cpu_types.hpp"

void lcpu(context_t *cpu, command_t *commands, const byte commands_count)
{
    while(true)
    {
        printf("RIP: %lld, stack: %ld\n", cpu->RIP, cpu->stack.size);
        if(cpu->RIP >= cpu->code.size)
        {
            printf("Unexpected end of code...\n");
            return;
        }

        byte id = grab_byte(cpu);
        if(id >= commands_count)
        {
            printf("Unexpected command[%x] at [%lld]!", id, cpu->RIP);
            return;
        }

        const char *result = commands[id](cpu);
        if(result != NULL)
        {
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

    context_t context = create_context(file);
    fclose(file);

    const byte commands_count = 9;
    command_t *commands = (command_t *)calloc(commands_count, sizeof(command_t));
    commands[0] = cpu_cmd_skip; 
    commands[1] = cpu_cmd_push; 
    commands[2] = cpu_cmd_add; 
    commands[3] = cpu_cmd_sub; 
    commands[4] = cpu_cmd_mul; 
    commands[5] = cpu_cmd_in; 
    commands[6] = cpu_cmd_out; 
    commands[7] = cpu_cmd_dup;  
    commands[8] = cpu_cmd_halt; 

    lcpu(&context, commands, commands_count);
}
