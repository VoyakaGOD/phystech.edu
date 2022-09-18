#include "mySort.hpp"

#define PUSH(l, r) stack_top->left = l; stack_top->right = r; stack_top++
#define POP(l, r) stack_top--; l = stack_top->left; r = stack_top->right

const int stack_size = 128;

static void Swap(char *first, char *second, size_t size)
{
    while((size--) > 0)
    {
        char tmp = *first;
        *first = *second;
        *second = tmp;
        first++;
        second++;
    }
}

typedef struct
{
    char *left;
    char *right;
} ArrayPart;

void MySort(void *array, size_t count, size_t size, compare_func_t compare)
{
    ArrayPart stack[stack_size];
    ArrayPart *stack_top = stack;

    PUSH((char *)array, (char *)array + (count - 1) * size);

    char *left = NULL;
    char *right = NULL;
    while(stack_top > stack)
    {
        POP(left, right);
        if(right - left < (long)size)
            continue;

        char *left0 = left;
        char *right0 = right;
        char *pivot = left + ((right - left) / (2 *size)) * size;

        while(left < right)
        {
            while(left < right && compare(left, pivot) < 0)
                left += size;
            while(left < right && compare(right, pivot) > 0)
                right -= size;

            if(left >= right)
                break;
            
            Swap(left, right, size);
            if(left == pivot)
                pivot = right;
            else if(right == pivot)
                pivot = left;
            
            if(compare(left, right) == 0)
                right -= size;
        }

        assert(stack_top - stack < stack_size - 2);
        
        PUSH(left0, left);
        PUSH(left + size, right0);
    }
}