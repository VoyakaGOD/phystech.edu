#include "stack.hpp"

int main()
{
    stack_t stack = {};
    stack_init(&stack, 1); stack_print_errors();
    stack_pop(&stack); stack_print_errors();
    printf("%d\n", stack_get_last_errors());
    for(int i = 0; i < 5; i++)
        stack_push(&stack, 5*i);
    stack_print_errors();
    for(int i = 0; i < 7; i++)
        printf("%d\n", stack_pop(&stack));
    stack_print_errors();
    getchar();
}