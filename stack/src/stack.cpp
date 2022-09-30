#include "stack.hpp"

#define CHECK_STACK(value) errors = 0;\
int err = stack_verify(stack);\
if(err)\
{\
    errors |= err;\
    return value;\
}\

static int errors = 0;

static void stack_resize_impl(stack_t *stack, size_t capacity)
{
    stack->capacity = capacity;
    stack->data = (elem_t *)realloc(stack->data, capacity);
    if(stack->data == NULL)
    {
        errors |= STACK_BAD_ALLOC;
        return;
    }

    for(int index = stack->size; index < capacity; index++)
        stack->data[index] = stack_poison;
}

int stack_get_last_errors()
{
    return errors;
}

int stack_verify(stack_t *stack)
{
    if(stack == NULL)
        return STACK_NULL_PTR;

    int err = 0;

    if(stack->data == NULL)
        err |= STACK_NULL_DATA;

    if(stack->size < 0)
        err |= STACK_NEGATIVE_SIZE;

    if(stack->capacity < 0)
        err |= STACK_NEGATIVE_CAPACITY;

    if(stack->size > stack->capacity)
        err |= STACK_OVERFLOW;

    return err;
}

void stack_init(stack_t *stack, size_t capacity)
{
    errors = 0; 
    if(stack == NULL) 
    { 
        errors = STACK_NULL_PTR; 
        return; 
    }

    stack->capacity = capacity;
    stack->size = 0;
    stack->data = NULL;

    stack_resize_impl(stack, capacity);
}

void stack_release(stack_t *stack)
{
    CHECK_STACK()

    stack->capacity = 0;
    stack->size = 0;
    free(stack->data);
    stack->data = NULL;
}

void stack_resize(stack_t *stack, size_t capacity)
{
    CHECK_STACK()

    if(capacity < stack->size)
    {
        errors |= STACK_BAD_RESIZE;
        return;
    }

    stack_resize_impl(stack, capacity);
}

void stack_push(stack_t *stack, elem_t item)
{
    CHECK_STACK()

    if(stack->size >= stack->capacity)
        stack_resize_impl(stack, 2 * stack->capacity);

    if(errors) return;
    
    stack->data[stack->size++] = item;
}

elem_t stack_peek(stack_t *stack)
{
    CHECK_STACK(stack_poison)

    if(stack->size == 0)
    {
        errors |= STACK_GET_ITEM_FROM_EMPTY;
        return stack_poison;
    }

    return stack->data[stack->size - 1];
}

elem_t stack_pop(stack_t *stack)
{
    elem_t item = stack_peek(stack);

    if(errors) return stack_poison;
    
    stack->data[--stack->size] = stack_poison;
    return item;
}

void stack_print_errors()
{
    if(errors & STACK_NULL_PTR)
        printf("*Pointer to the stack was null.\n");
    if(errors & STACK_NULL_DATA)
        printf("*Pointer to the data of stack was null.\n");
    if(errors & STACK_NEGATIVE_CAPACITY)
        printf("*Stack have negative capacity.\n");
    if(errors & STACK_NEGATIVE_SIZE)
        printf("*Stack have negative size.\n");
    if(errors & STACK_OVERFLOW)
        printf("*Size of the stack greater than capacity.\n");
    if(errors & STACK_BAD_ALLOC)
        printf("*Problems with memory allocation.\n");
    if(errors & STACK_GET_ITEM_FROM_EMPTY)
        printf("*Try to pop or peek item from empty stack.\n");
    if(errors & STACK_BAD_RESIZE)
        printf("*New stack capacity is lower than size.\n");
}