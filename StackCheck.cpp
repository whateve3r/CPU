#include "StackCheck.h"

int StackCheck(const Stack* stack)
{
    if (stack == NULL)
    {
        return NULL_POINTER;
    }

    if (stack->data == NULL)
    {
        return NULL_STACK;
    }

    if (stack->capacity < 0)
    {
        return NEGATIVE_CAPACITY;
    }

    if (stack->size < 0)
    {
        return NEGATIVE_SIZE;
    }

    if (stack->size > stack->capacity)
    {
        return SizeCapacityERROR;
    }

    if (stack->data[0] != FIRST_CANARY)
    {
        return FIRST_CANARY_ERROR;
    }

    if (stack->data[stack->capacity+1] != LAST_CANARY)
    {
        return LAST_CANARY_ERROR;
    }

    return 0;
}

void StackDump(const Stack* stack)
{
    PrintError(stack);
    printf("stack data - %p\n", stack->data);
    printf("stack capacity - %d\n", stack->capacity);
    printf("stack size - %d\n", stack->size);
}

void PrintError(const Stack* stack)
{
    int NumError = 0;

    NumError = StackCheck(stack);

    if (NumError == NULL_POINTER)
    {
        printf("ERROR: NULL POINTER\n");
    }

    if (NumError == NULL_STACK)
    {
        printf("ERROR: NULL STACK\n");
    }

    if (NumError == NEGATIVE_CAPACITY)
    {
        printf("ERROR: NEGATIVE CAPACITY\n");
    }

    if (NumError == NEGATIVE_SIZE)
    {
        printf("ERROR: NEGATIVE SIZE\n");
    }

    if (NumError == SizeCapacityERROR)
    {
        printf("ERROR: SIZE IS MORE THAN CAPACITY\n");
    }

    if (NumError == FIRST_CANARY_ERROR)
    {
        printf("ERROR: FIRST CANARY ERROR\n");
    }

    if (NumError == LAST_CANARY_ERROR)
    {
        printf("ERROR: LAST CANARY ERROR\n");
    }
}

int Verificator(const Stack* stack)
{
    if (StackCheck(stack) != 0)
    {
        StackDump(stack);
        assert(0);
    }

    return SUCCESS;
}
