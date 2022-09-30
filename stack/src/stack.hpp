#ifndef STACK_HEADER
#define STACK_HEADER

#include <stdlib.h>
#include <stdio.h>

typedef int elem_t;

const elem_t stack_poison = 0x00BADFAD;

enum stack_error
{
    STACK_NULL_PTR = 1,
    STACK_NULL_DATA = 2,
    STACK_NEGATIVE_CAPACITY = 4,
    STACK_NEGATIVE_SIZE = 8,
    STACK_OVERFLOW = 16,
    STACK_BAD_ALLOC = 32,
    STACK_GET_ITEM_FROM_EMPTY = 64,
    STACK_BAD_RESIZE = 128
};

typedef struct
{
    size_t capacity;
    size_t size;
    elem_t *data;
} stack_t;

int stack_get_last_errors();

int stack_verify(stack_t *stack);

void stack_init(stack_t *stack, size_t capacity);

void stack_release(stack_t *stack);

void stack_resize(stack_t *stack, size_t capacity);

void stack_push(stack_t *stack, elem_t item);

elem_t stack_peek(stack_t *stack);

elem_t stack_pop(stack_t *stack);

void stack_print_errors();

#endif //STACK_HEADER