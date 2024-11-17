#include "consts.h"
#include "StackStruct.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef StackChecking
#define StackChecking
int StackCheck(const Stack* stack);
int StackDump(const Stack* stack);
int Verificator(const Stack* stack);
int PrintError(const Stack* stack);
#endif
