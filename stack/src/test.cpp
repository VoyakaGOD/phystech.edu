#include "stack.hpp"

int main()
{
    set_log_file("log.txt");
    stack_dump_data_size = -1;

    stack_t stack = {};
    STACK_INIT(stack, 1); stack_print_errors(stdout);
    stack_push(&stack, 999);
    stack_resize(&stack, 0); stack_print_errors(stdout);
    printf("%d\n", stack_pop(&stack)); stack_print_errors(stdout);
    printf("%d\n", stack_pop(&stack)); stack_print_errors(stdout);
    for(int i = 0; i < 5; i++)
        stack_push(&stack, 5*i);
    stack_print_errors(stdout);
    STACK_DUMP(stack);
    for(int i = 0; i < 7; i++)
        printf("%d\n", stack_pop(&stack));
    stack_print_errors(stdout);
    STACK_DUMP(stack);
    getchar();
}