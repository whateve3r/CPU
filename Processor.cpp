#include "Processor.h"

int CPU(Stack* stack)
{
    Verificator(stack);

    FILE* CPUCommands = fopen("CPUCommands.txt", "r");

    stackElem argument = 0;

    int NumberOfCommand = 0;

    while (fscanf(CPUCommands, "%d", &NumberOfCommand) == 1)
    {
        switch(NumberOfCommand)
        {
            case PUSH:
                fscanf(CPUCommands, "%lg", &argument);
                Push(stack, argument);
                break;

            case POP:
                Pop(stack);
                break;

            case MUL:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                Pop(stack);
                Pop(stack);

                Push(stack, Elem2 * Elem1);
                break;
            }

            case DIV:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                Pop(stack);
                Pop(stack);

                Push(stack, Elem2 / Elem1);
               break;
            }

            case SUM:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                Pop(stack);
                Pop(stack);

                Push(stack, Elem2 + Elem1);
                break;
            }

            case SUB:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                Pop(stack);
                Pop(stack);

                Push(stack, Elem2 - Elem1);
                break;
            }

            case OUT:
                PrintStack(stack);
                break;

            case HLT:
                break;

            default:
                fprintf(stderr, "SWITCH ERROR\n");
        }
    }

    Verificator(stack);

    fclose(CPUCommands);
    StackDestruct(stack);

    return SUCCESS;
}
