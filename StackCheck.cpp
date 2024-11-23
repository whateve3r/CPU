#include "StackCheck.h"

int StackCheck(const Stack* stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "ERROR: STACK POINTER IS NULL\n");
        assert(0);
    }

    if (stack->data == NULL)
    {
        fprintf(stderr, "ERROR: DATA POINTER IS NULL\n");
        return DATA_POINTER;
    }

    if (stack->capacity < 0)
    {
        fprintf(stderr, "ERROR: NEGATIVE CAPACITY\n");
        return NEGATIVE_CAPACITY;
    }

    if (stack->size < 0)
    {
        fprintf(stderr, "ERROR: NEGATIVE SIZE\n");
        return NEGATIVE_SIZE;
    }

    if (stack->size > stack->capacity)
    {
        fprintf(stderr, "ERROR: STACK OVERFLOW\n");
        return STACK_OVERFLOW;
    }

    if (stack->data[0] != FIRST_CANARY)
    {
        fprintf(stderr, "ERROR: FIRST CANARY MISMATCH\n");
        return FIRST_CANARY_ERROR;
    }

    if (stack->data[stack->capacity+1] != LAST_CANARY)
    {
        fprintf(stderr, "ERROR: LAST CANARY MISMATCH\n");
        return LAST_CANARY_ERROR;
    }

    return SUCCESS;
}

int StackDump(const Stack* stack)
{
    printf("stack data - %p\n", stack->data);
    printf("stack capacity - %d\n", stack->capacity);
    printf("stack size - %d\n", stack->size);

    return SUCCESS;
}

int Verificator(const Stack* stack)
{
    if (StackCheck(stack) != SUCCESS)
    {
        StackDump(stack);
        assert(0);
    }

    return SUCCESS;
}
