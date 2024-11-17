#include "StackCheck.h"
#include <stdio.h>
#include <stdlib.h>
#define MULTIPLIER 2

#ifndef stack1
#define stack1
int StackConstruct(Stack* stack, int capacity);
int StackDestruct(Stack* stack);
int StackResize(Stack* stack);

int push(Stack* stack, const double value);
stackElem pop(Stack* stack);

int PrintStack(const Stack* stack);
#endif
