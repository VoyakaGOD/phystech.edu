#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>

typedef int elem_t;

typedef struct
{
    size_t capacity;
    size_t size;
    elem_t *data;
} stack_t;

void stack_init(stack_t *stack, size_t capacity);

void stack_release(stack_t *stack);

void stack_resize(stack_t *stack, size_t capacity);

void stack_push(stack_t *stack, elem_t item);

elem_t stack_peek(stack_t *stack);

elem_t stack_pop(stack_t *stack);

#endif //STACK_HEADER