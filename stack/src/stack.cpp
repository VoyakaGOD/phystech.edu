#include "stack.hpp"

void stack_init(stack_t *stack, size_t capacity)
{
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = NULL;

    stack_resize(stack, capacity);
}

void stack_release(stack_t *stack)
{
    stack->capacity = 0;
    stack->size = 0;
    free(stack->data);
    stack->data = NULL;
}

void stack_resize(stack_t *stack, size_t capacity)
{
    stack->capacity = capacity;
    stack->data = (elem_t *)realloc(stack->data, capacity);

    for(int index = stack->size; index < capacity; index++)
        stack->data[index] = stack_poison;
}

void stack_push(stack_t *stack, elem_t item)
{
    if(stack->size >= stack->capacity)
        stack_resize(stack, 2 * stack->capacity);
    
    stack->data[stack->size++] = item;
}

elem_t stack_peek(stack_t *stack)
{
    return stack->data[stack->size - 1];
}

elem_t stack_pop(stack_t *stack)
{
    elem_t item = stack_peek(stack);
    stack->data[--stack->size] = stack_poison;
    return item;
}