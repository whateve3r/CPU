#include "Compiler.h"
#include <string.h>

int main()
{
    Stack MyStack;

    StackConstruct(&MyStack, 5);

    ReadUserCommands("UserCommands.txt");

    CPU(&MyStack);
}
