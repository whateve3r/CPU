#include "stackfunc.h"

int StackConstruct(Stack* stack, int capacity)
{
    stack->data = (stackElem*)calloc((size_t)capacity+2, sizeof(stackElem));

    stack->size = 0;
    stack->capacity = capacity;
    stack->data[0] = FIRST_CANARY;
    stack->data[capacity+1] = LAST_CANARY;

    Verificator(stack);

    return 0;
}

int StackDestruct(Stack* stack)
{
    if (stack == NULL)
    {
        return NULL_POINTER;
    }

    free(stack->data);

    stack->size = -1;
    stack->capacity = -1;
    stack->data = NULL;

    return SUCCESS;
}

int StackResize(Stack* stack)
{
    if (stack == NULL)
    {
        return NULL_POINTER;
    }

    stack->capacity *= MULTIPLIER;
    stack->data = (stackElem*)realloc(stack->data, ((size_t)stack->capacity+2) * sizeof(stackElem));
    stack->data[stack->capacity+1] = LAST_CANARY;

    Verificator(stack);

    return 0;
}

int push(Stack* stack, const double value)
{
    Verificator(stack);

    if (stack->size >= stack->capacity)
    {
        StackResize(stack);
    }

    stack->data[stack->size + 1] = value;
    stack->size++;

    Verificator(stack);

    return 0;
}

stackElem pop(Stack* stack)
{
    stackElem value = 0;

    Verificator(stack);

    stack->size--;

    Verificator(stack);

    value = stack->data[stack->size + 1];

    Verificator(stack);

    return value;
}


void PrintStack(const Stack* stack)
{
    printf("Stack size - %d\n", stack->size);
    printf("Stack capacity - %d\n", stack->capacity);

    printf("Elements of stack:\n");

    for (int i = 1; i < stack->size + 1; i++)
    {
        printf("%d - %lg\n", i,  stack->data[i]);
    }
}
