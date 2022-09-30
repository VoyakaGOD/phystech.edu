#include "stack.hpp"
#include <stdio.h>

int main()
{
    stack_t stack = {};
    stack_init(&stack, 1);
    for(int i = 0; i < 5; i++)
        stack_push(&stack, 5*i);
    for(int i = 0; i < 5; i++)
        printf("%d\n", stack_pop(&stack));
    getchar();
}