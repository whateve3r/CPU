#include "Processor.h"

void CPU(Stack* MyStack)
{
    FILE* CPUCommands = fopen("CPUCommands.txt", "r");

    stackElem argument = 0;

    int QuantityOfPush = 0;
    int NumberOfCommand = 0;

    while (fscanf(CPUCommands, "%d", &NumberOfCommand) == 1)
    {
        switch(NumberOfCommand)
        {
            case 1:
                fscanf(CPUCommands, "%lg", &argument);
                push(MyStack, argument);
                QuantityOfPush++;
                break;

            case 2:
            {
                double Elem1 = MyStack->data[QuantityOfPush];
                double Elem2 = MyStack->data[QuantityOfPush - 1];

                pop(MyStack);
                pop(MyStack);

                push(MyStack, Elem2 * Elem1);
                QuantityOfPush--;
                break;
            }

            case 3:
            {
                double Elem1 = MyStack->data[QuantityOfPush];
                double Elem2 = MyStack->data[QuantityOfPush - 1];

                pop(MyStack);
                pop(MyStack);

                push(MyStack, Elem2 / Elem1);
                QuantityOfPush--;
               break;
            }

            case 4:
            {
                double Elem1 = MyStack->data[QuantityOfPush];
                double Elem2 = MyStack->data[QuantityOfPush - 1];

                pop(MyStack);
                pop(MyStack);

                push(MyStack, Elem2 - Elem1);
                QuantityOfPush--;
                break;
            }

            case 5:
            {
                double Elem1 = MyStack->data[QuantityOfPush];
                double Elem2 = MyStack->data[QuantityOfPush - 1];

                pop(MyStack);
                pop(MyStack);

                push(MyStack, Elem2 + Elem1);
                QuantityOfPush--;
                break;
            }

            case 0:
                PrintStack(MyStack);
                break;

            case -1:
                break;

            default:
                printf("SWITCH ERROR\n");
        }
    }

    fclose(CPUCommands);
    StackDestruct(MyStack);
}
