#include "stackfunc.h"
#include <string.h>

int main()
{
    Stack MyStack;

    StackConstruct(&MyStack, 5);

    FILE* commands = fopen("commands.txt", "r");
    fseek(commands, 0, SEEK_END);
    size_t Size = (size_t)ftell(commands);
    rewind(commands);

    char* Command = (char*)calloc(Size, sizeof(char));

    int QuantityOfPush = 0;
    double num = 0;

    while (fgets(Command, (int)Size, commands) != NULL)
    {
        if (sscanf(Command, "push %lg\n", &num) == 1)
        {
            push(&MyStack, num);
            QuantityOfPush++;
        }

        if (strcmp(Command, "mul\n") == 0)
        {
            double Elem1 = MyStack.data[QuantityOfPush];
            double Elem2 = MyStack.data[QuantityOfPush - 1];
            pop(&MyStack);
            pop(&MyStack);
            push(&MyStack, Elem2 * Elem1);
            QuantityOfPush--;
        }

        if (strcmp(Command, "div\n") == 0)
        {
            double Elem1 = MyStack.data[QuantityOfPush];
            double Elem2 = MyStack.data[QuantityOfPush - 1];
            pop(&MyStack);
            pop(&MyStack);
            push(&MyStack, Elem2 / Elem1);
            QuantityOfPush--;
        }

        if (strcmp(Command, "sub\n") == 0)
        {
            double Elem1 = MyStack.data[QuantityOfPush];
            double Elem2 = MyStack.data[QuantityOfPush - 1];
            pop(&MyStack);
            pop(&MyStack);
            push(&MyStack, Elem2 - Elem1);
            QuantityOfPush--;
        }

        if (strcmp(Command, "out\n") == 0)
        {
            PrintStack(&MyStack);
        }

        if (strcmp(Command, "hlt\n") == 0)
        {
            break;
        }
    }

    free(Command);
    fclose(commands);
    StackDestruct(&MyStack);
}
