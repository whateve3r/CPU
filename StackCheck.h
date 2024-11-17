#include "consts.h"
#include "StackStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef StackChecking
#define StackChecking
int StackCheck(const Stack* stack);
void StackDump(const Stack* stack);
int Verificator(const Stack* stack);
void PrintError(const Stack* stack);
#endif
