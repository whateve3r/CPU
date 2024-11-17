#include "Processor.h"

void CPU(Stack* stack)
{

    Verificator(stack);

    FILE* CPUCommands = fopen("CPUCommands.txt", "r");

    stackElem argument = 0;

    int NumberOfCommand = 0;

    while (fscanf(CPUCommands, "%d", &NumberOfCommand) == 1)
    {
        switch(NumberOfCommand)
        {
            case 1:
                fscanf(CPUCommands, "%lg", &argument);
                push(stack, argument);
                break;

            case 2:
                pop(stack);
                break;

            case 3:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                pop(stack);
                pop(stack);

                push(stack, Elem2 * Elem1);
                break;
            }

            case 4:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                pop(stack);
                pop(stack);

                push(stack, Elem2 / Elem1);
               break;
            }

            case 5:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                pop(stack);
                pop(stack);

                push(stack, Elem2 + Elem1);
                break;
            }

            case 6:
            {
                double Elem1 = stack->data[stack->size];
                double Elem2 = stack->data[stack->size - 1];

                pop(stack);
                pop(stack);

                push(stack, Elem2 - Elem1);
                break;
            }

            case 0:
                PrintStack(stack);
                break;

            case -1:
                break;

            default:
                printf("SWITCH ERROR\n");
        }
    }

    Verificator(stack);

    fclose(CPUCommands);
    StackDestruct(stack);
}
